#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<omp.h>
#include<stdint.h>
#include<atomic>
#include "util.cpp"

#define CACHELINE_SZ (64)

struct SharedData_t{
	volatile uint64_t dummy1[CACHELINE_SZ/sizeof(uint64_t)]; // avoid buddy cacheline prefetching
	volatile uint64_t data[CACHELINE_SZ/sizeof(uint64_t)];
	volatile uint64_t dummy2[CACHELINE_SZ/sizeof(uint64_t)]; // avoid buddy cacheline prefetching
}__attribute__((aligned(64)));

SharedData_t ** trueSharingData;

using namespace std;

int main(int argc, char ** argv){
	int nGroups = -1;
	int nThreads = -1;
	int nIter = -1;
	float * shareFracArray;
	//int * groupDelimiter;
	int * threadList;
	int * threadGroup;
	int * groupMarker;
	float * readFracArray;

	ParseArg(argc, argv, nIter, nGroups, nThreads, shareFracArray, groupMarker, readFracArray, threadList);	

	trueSharingData = (SharedData_t **) malloc ((nGroups) * sizeof(struct SharedData_t *));

	for(int i = 0; i < nGroups; i++) {
		trueSharingData[i] = (SharedData_t *) malloc (sizeof(struct SharedData_t));
	}
	atomic<uint64_t> justToAvoidCompilerOptimization;	

	#pragma omp parallel num_threads(nThreads) firstprivate(nIter)
	{
		int me = omp_get_thread_num();
		int thread_index = threadList[me];
		int shared_data_index = groupMarker[thread_index];
		int read_write_flag = readFracArray[me];
		long private_counter = 0;
		long shared_data_counter = 0;
		volatile uint64_t *tsData;
		int shareFrac = (int) shareFracArray[shared_data_index];
		int readFrac = (int) readFracArray[me];
		tsData = &(trueSharingData[shared_data_index]->data[0]);

		volatile uint64_t privateData;
		//volatile uint64_t privateData;
		//printf("public address: %lx\n", tsData);
		//printf("private address: %lx\n", &privateData);
		uint64_t i;
		int read_counter = 0;
		int write_counter = 0;
		//printf("thread: %d, shared_data_index: %d\n", me, shared_data_index);
		for(i = 0 ; i < nIter; i++) {
			// Use RDTSC as a proxy random number generator
			unsigned long lo, hi;
		        asm volatile( "rdtsc" : "=a" (lo), "=d" (hi) ); 
        		int rNum  = (lo % 54121) % 100; // mod by a prime.
			// if the random number is < shareFrac, perform a local memory operation
			if (rNum < shareFrac) {
			// Else touch the data that is considered to be "owned" by me.

			// before
			asm volatile( "rdtsc" : "=a" (lo), "=d" (hi) ); 
        		int rNum1  = (lo % 53419) % 100; // mod by a prime.
			// after
			if(rNum1 < readFrac) {
				//printf("thread %d is reading\n", me);
				__asm__ __volatile__ ("movl %1, %%edx;"
				"addl %%edx, %0;"
				: "=r" (rNum)
				: "m" (*tsData)
				: "%ebx");
				read_counter++;
				//printf("in thread %d\n", me);
			} else {
			//*tsData = rNum2;
				//printf("thread  %d is writing\n", me);
				__asm__ __volatile__ ("movl %1, %%ebx;"
                                "addl %%ebx, %0;"
                                : "=m" (*tsData)
                                : "r" (rNum)
                                : "%ebx");
				write_counter++;
				//printf("in thread %d\n", me);
			}
			shared_data_counter++;			
			} else {
			  //printf("it is executed %d\n", i);
			  //privateData = rNum;
			 __asm__ __volatile__ ("movl %1, %%ebx;"
			"addl %%ebx, %0;"
			: "=m" (privateData)
			: "r" (rNum)
			: "%ebx");
			private_counter++;	
			}
		}
		printf("in thread: %d, shared data counter: %ld, private counter: %ld, share fraction: %d read counter: %d, write counter: %d, read frac: %d\n", me, shared_data_counter, private_counter, shareFrac, read_counter, write_counter, readFrac);
		printf("%d\t%ld\t%ld\n", me, shared_data_counter, private_counter);
		justToAvoidCompilerOptimization += *tsData;		
		justToAvoidCompilerOptimization += privateData;
	}

        for(int i = 0; i < nGroups; i++) {
                free(trueSharingData[i]);
        }
	free(trueSharingData);
	return justToAvoidCompilerOptimization.load() ^ justToAvoidCompilerOptimization.load();
}
