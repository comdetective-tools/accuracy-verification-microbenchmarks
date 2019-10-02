#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<omp.h>
#include<stdint.h>
#include<atomic>
#include "util.cpp"

#define CACHELINE_SZ (64)

//#define USE_ATOMIC_ADD 1
//#define USE_ATOMIC_EXCHG 1
//#define USE_ATOMIC_WRITE 1

struct SharedData_t{
	volatile uint64_t dummy1[CACHELINE_SZ/sizeof(uint64_t)]; // avoid buddy cacheline prefetching
	//volatile uint64_t data[CACHELINE_SZ/sizeof(uint64_t)]; 
	atomic<uint64_t> data[CACHELINE_SZ/sizeof(uint64_t)]; 
	volatile uint64_t dummy2[CACHELINE_SZ/sizeof(uint64_t)]; // avoid buddy cacheline prefetching
}__attribute__((aligned(64)));


SharedData_t falseSharingData;
SharedData_t trueSharingData;

using namespace std;

int main(int argc, char ** argv){
	int nThreads = -1;
	float shareFrac = -1;
	float falseShareFrac = -1;
	uint64_t nIter = -1;

	ParseArg(argc, argv, nThreads, shareFrac, falseShareFrac, nIter);

	atomic<uint64_t> justToAvoidCompilerOptimization;

#if USE_ATOMIC_EXCHG
	printf("USE_ATOMIC_EXCHG is activated\n");
#elif USE_ATOMIC_ADD
	printf("USE_ATOMIC_ADD is activated\n");
#elif USE_ATOMIC_WRITE                 
	printf("USE_ATOMIC_WRITE is activated\n");
#else
        assert(0 && "NYI");
#endif


	#pragma omp parallel num_threads(nThreads)
	{
		int me = omp_get_thread_num();
		//volatile uint64_t *fsData = &falseSharingData.data[me];
		//volatile uint64_t *tsData = &trueSharingData.data[0];
		//volatile uint64_t *privateData = &(new SharedData_t())->data[0];
		int truesharingcount = 0;
		int falsesharingcount = 0;
		atomic<uint64_t> *fsData = &falseSharingData.data[me];
		atomic<uint64_t> *tsData = &trueSharingData.data[0];
		atomic<uint64_t> *privateData = &(new SharedData_t())->data[0];
		for(uint64_t i = 0 ; i < nIter; i++) {
			// Use RDTSC as a proxy random number generator
			unsigned long lo, hi;
		        asm volatile( "rdtsc" : "=a" (lo), "=d" (hi) ); 
        		int rNum  = (lo % 54121) % 100; // mod by a prime.
			// if the random number is < shareFrac, perform a local memory operation
			if (rNum < shareFrac) {
				// A local op
				__asm__ __volatile__ ("MFENCE;");
#if USE_ATOMIC_EXCHG
				atomic_exchange(privateData, (uint64_t) rNum) ;
#elif USE_ATOMIC_ADD
				*privateData += rNum;
#elif USE_ATOMIC_WRITE
				*privateData = rNum;
#else
				assert(0 && "NYI");
#endif
			} else {
				// if the random number is > shareFrac, perform an op on the shared cacheline
        			int rNum2  = (lo % 53419) % 100; // mod by a prime.
				if (rNum2 < falseShareFrac) {
					// if the rNum2 < falseShareFrac, perform a "true sharing" op
					// That is, touch the data that was previously accessed by another thread.
					truesharingcount++;
					__asm__ __volatile__ ("MFENCE;");
#if USE_ATOMIC_EXCHG
					atomic_exchange(tsData, (uint64_t) rNum2);
#elif USE_ATOMIC_ADD
					*tsData += rNum2;
#elif USE_ATOMIC_WRITE
					*tsData = rNum2;
#else
                                assert(0 && "NYI");
#endif

				} else {
					// Else touch the data that is considered to be "owned" by me.
					falsesharingcount++;
					__asm__ __volatile__ ("MFENCE;");
#if USE_ATOMIC_EXCHG
					atomic_exchange(fsData, (uint64_t) rNum2);
#elif USE_ATOMIC_ADD
					*fsData += rNum2;
#elif USE_ATOMIC_WRITE                 
					*fsData = rNum2;
#else                           
                                	assert(0 && "NYI");
#endif
				}
			}
		}
		printf("in thread %d, truesharingcount: %d\n", me, truesharingcount);
		printf("in thread %d, falsesharingcount: %d\n", me, falsesharingcount);
		justToAvoidCompilerOptimization += *fsData;		
		justToAvoidCompilerOptimization += *tsData;		
		justToAvoidCompilerOptimization += *privateData;		
	}

	
	return justToAvoidCompilerOptimization.load() ^ justToAvoidCompilerOptimization.load();
}
