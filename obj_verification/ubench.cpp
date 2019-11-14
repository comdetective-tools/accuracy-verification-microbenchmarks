#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<omp.h>
#include<stdint.h>
#include<atomic>
#include "util.cpp"

#define CACHELINE_SZ (64)

//#define USE_GLOBAL_DATA 1
//#define USE_MALLOC 1
//#define USE_STACK 1
//#define USE_CALLOC 1
#define USE_NEW 1
//#define USE_ALIGNED_ALLOC 1
//#define USE_REALLOC 1
//#define USE_MEMALIGN 1
//#define USE_POSIX_MEMALIGN 1
//#define USE_VALLOC 1
//#define USE_PVALLOC 1

struct SharedData_t{
	volatile uint64_t dummy1[CACHELINE_SZ/sizeof(uint64_t)]; // avoid buddy cacheline prefetching
	//volatile uint64_t data[CACHELINE_SZ/sizeof(uint64_t)]; 
	atomic<uint64_t> data[CACHELINE_SZ/sizeof(uint64_t)]; 
	volatile uint64_t dummy2[CACHELINE_SZ/sizeof(uint64_t)]; // avoid buddy cacheline prefetching
}__attribute__((aligned(64)));


SharedData_t tsGlobalData;
SharedData_t fsGlobalData;

using namespace std;

int main(int argc, char ** argv){
	int nThreads = -1;
	float shareFrac = -1;
	float falseShareFrac = -1;
	uint64_t nIter = -1;

	ParseArg(argc, argv, nThreads, shareFrac, falseShareFrac, nIter);

	atomic<uint64_t> justToAvoidCompilerOptimization;

	SharedData_t * tsMallocData = (SharedData_t *) malloc (sizeof(SharedData_t));
	SharedData_t * fsMallocData = (SharedData_t *) malloc (sizeof(SharedData_t));
	SharedData_t * tsCallocData = (SharedData_t *) calloc (1, sizeof(SharedData_t));
        SharedData_t * fsCallocData = (SharedData_t *) calloc (1, sizeof(SharedData_t));
	SharedData_t * tsNewData = new SharedData_t();
	SharedData_t * fsNewData = new SharedData_t();
	SharedData_t tsStackData;
	SharedData_t fsStackData;

	#pragma omp parallel num_threads(nThreads)
	{
		int me = omp_get_thread_num();
		//volatile uint64_t *fsData = &falseSharingData.data[me];
		//volatile uint64_t *tsData = &trueSharingData.data[0];
		//volatile uint64_t *privateData = &(new SharedData_t())->data[0];
		int truesharingcount = 0;
#if USE_GLOBAL_DATA
		atomic<uint64_t> *tsGData = &tsGlobalData.data[0];
		atomic<uint64_t> *fsGData = &fsGlobalData.data[me];
		printf("tsGlobalData: %lx, tsGData: %lx\n", &tsGlobalData.dummy1[0], tsGData);
#elif USE_MALLOC
		atomic<uint64_t> *tsMData = &(tsMallocData->data[0]);
		atomic<uint64_t> *fsMData = &(tsMallocData->data[me]);
		printf("tsMallocData: %lx, tsMData: %lx\n", &tsMallocData->dummy1[0], tsMData);
#elif USE_STACK
                atomic<uint64_t> *tsSData = &tsStackData.data[0];
                atomic<uint64_t> *fsSData = &fsStackData.data[me];
		printf("tsStackData: %lx, tsSData: %lx\n", &tsStackData.dummy1[0], tsSData);
#elif USE_CALLOC
                atomic<uint64_t> *tsCData = &(tsCallocData->data[0]);
                atomic<uint64_t> *fsCData = &(fsCallocData->data[me]);
		printf("tsCallocData: %lx, tsCData: %lx\n", &tsCallocData->dummy1[0], tsCData);
#elif USE_NEW
                atomic<uint64_t> *tsNData = &(tsNewData->data[0]);
                atomic<uint64_t> *fsNData = &(fsNewData->data[me]);
		printf("tsNewData: %lx, tsNData: %lx\n", &tsNewData->dummy1[0], tsNData);
#else
		assert(0 && "NYI");
#endif		
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
				*privateData += rNum;
			} else {
				// if the random number is > shareFrac, perform an op on the shared cacheline
					// if the rNum2 < falseShareFrac, perform a "true sharing" op
					// That is, touch the data that was previously accessed by another thread.

				// before
				int rNum2  = (lo % 53419) % 100; // mod by a prime.
                                if (rNum2 < falseShareFrac) {
                                        // if the rNum2 < falseShareFrac, perform a "true sharing" op
                                        // That is, touch the data that was previously accessed by another thread.
                                        __asm__ __volatile__ ("MFENCE;");
#if USE_GLOBAL_DATA
                                	*tsGData += rNum;
#elif USE_MALLOC
                                	*tsMData += rNum;
#elif USE_STACK
                                        *tsSData += rNum;
#elif USE_CALLOC
                                        *tsCData += rNum;
#elif USE_NEW
                                        *tsNData += rNum;
#else
                                	assert(0 && "NYI");
#endif

                                } else {
                                        // Else touch the data that is considered to be "owned" by me.
                                        __asm__ __volatile__ ("MFENCE;");
#if USE_GLOBAL_DATA
                                        *fsGData += rNum;
#elif USE_MALLOC
                                        *fsMData += rNum;
#elif USE_STACK
                                        *fsSData += rNum;
#elif USE_CALLOC
                                        *fsCData += rNum;
#elif USE_NEW
                                        *fsNData += rNum;
#else
                                        assert(0 && "NYI");
#endif
                                }
				// after
			}
		}
#if USE_GLOBAL_DATA		
		justToAvoidCompilerOptimization += *tsGData;
		justToAvoidCompilerOptimization += *fsGData;
#elif USE_MALLOC
		justToAvoidCompilerOptimization += *tsMData;
		justToAvoidCompilerOptimization += *fsMData;
#elif USE_STACK
                justToAvoidCompilerOptimization += *tsSData;
                justToAvoidCompilerOptimization += *fsSData;
#elif USE_CALLOC
                justToAvoidCompilerOptimization += *tsCData;
                justToAvoidCompilerOptimization += *fsCData;
#elif USE_NEW
                justToAvoidCompilerOptimization += *tsNData;
                justToAvoidCompilerOptimization += *fsNData;
#else
                assert(0 && "NYI");
#endif		
		justToAvoidCompilerOptimization += *privateData;		
	}
	free(tsMallocData);
	free(fsMallocData);
	
	return justToAvoidCompilerOptimization.load() ^ justToAvoidCompilerOptimization.load();
}
