#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<omp.h>
#include<stdint.h>
#include<atomic>
#include<cassert>
#include <malloc.h>
#include <numa.h>
#include "util.cpp"

#define CACHELINE_SZ (64)
//#define USE_GLOBAL_DATA 1
//#define USE_MALLOC 1
#define USE_STACK 1
//#define USE_CALLOC 1
//#define USE_NEW 1
//#define USE_ALIGNED_ALLOC 1
//#define USE_REALLOC 1
//#define USE_MEMALIGN 1
//#define USE_POSIX_MEMALIGN 1
//#define USE_VALLOC 1
//#define USE_PVALLOC 1
//#define USE_NUMA_ALLOC_ONNODE 1
//#define USE_NUMA_ALLOC_INTERLEAVED 1
//#define USE_MMAP 1
//#define USE_MMAP64 1

#if USE_MMAP || USE_MMAP64
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#endif

struct SharedData_t{
	volatile uint64_t dummy1[CACHELINE_SZ/sizeof(uint64_t)]; // avoid buddy cacheline prefetching
	//volatile uint64_t data[CACHELINE_SZ/sizeof(uint64_t)]; 
	atomic<uint64_t> data[CACHELINE_SZ/sizeof(uint64_t)]; 
	volatile uint64_t dummy2[CACHELINE_SZ/sizeof(uint64_t)]; // avoid buddy cacheline prefetching
}__attribute__((aligned(64)));

#if USE_GLOBAL_DATA
SharedData_t tsGlobalData;
SharedData_t fsGlobalData;
#endif

using namespace std;

int main(int argc, char ** argv){
	int nThreads = -1;
	float shareFrac = -1;
	float falseShareFrac = -1;
	uint64_t nIter = -1;

	ParseArg(argc, argv, nThreads, shareFrac, falseShareFrac, nIter);

	atomic<uint64_t> justToAvoidCompilerOptimization;
#if USE_GLOBAL_DATA
#elif USE_MALLOC
	SharedData_t * tsMallocData = (SharedData_t *) malloc (sizeof(SharedData_t));
	SharedData_t * fsMallocData = (SharedData_t *) malloc (sizeof(SharedData_t));
#elif USE_CALLOC
	SharedData_t * tsCallocData = (SharedData_t *) calloc (1, sizeof(SharedData_t));
        SharedData_t * fsCallocData = (SharedData_t *) calloc (1, sizeof(SharedData_t));
#elif USE_ALIGNED_ALLOC
	SharedData_t * tsAlignedAllocData = (SharedData_t *) aligned_alloc (64, sizeof(SharedData_t));
	SharedData_t * fsAlignedAllocData = (SharedData_t *) aligned_alloc (64, sizeof(SharedData_t));
#elif USE_REALLOC
	SharedData_t * tsReallocData = (SharedData_t *) realloc (NULL, sizeof(SharedData_t));
	SharedData_t * fsReallocData = (SharedData_t *) realloc (NULL, sizeof(SharedData_t));
#elif USE_MEMALIGN
	SharedData_t * tsMemalignData = (SharedData_t *) memalign (64, sizeof(SharedData_t));
	SharedData_t * fsMemalignData = (SharedData_t *) memalign (64, sizeof(SharedData_t));
#elif USE_VALLOC
	SharedData_t * tsVallocData = (SharedData_t *) valloc (sizeof(SharedData_t));
	SharedData_t * fsVallocData = (SharedData_t *) valloc (sizeof(SharedData_t));
#elif USE_PVALLOC
	SharedData_t * tsPvallocData = (SharedData_t *) pvalloc (sizeof(SharedData_t));
	SharedData_t * fsPvallocData = (SharedData_t *) pvalloc (sizeof(SharedData_t));
#elif USE_NUMA_ALLOC_ONNODE
	SharedData_t * tsNAOnnodeData = (SharedData_t *) numa_alloc_onnode(sizeof(SharedData_t), 0);
	SharedData_t * fsNAOnnodeData = (SharedData_t *) numa_alloc_onnode(sizeof(SharedData_t), 0);
#elif USE_NUMA_ALLOC_INTERLEAVED
	SharedData_t * tsNAInterleavedData = (SharedData_t *) numa_alloc_interleaved(sizeof(SharedData_t));
	SharedData_t * fsNAInterleavedData = (SharedData_t *) numa_alloc_interleaved(sizeof(SharedData_t));
#elif USE_POSIX_MEMALIGN
	void * tsPosixMemalignData; 
	posix_memalign(&tsPosixMemalignData, 64, sizeof(SharedData_t));
	void * fsPosixMemalignData; 
	posix_memalign(&fsPosixMemalignData, 64, sizeof(SharedData_t));
#elif USE_STACK
	SharedData_t tsStackData;
	SharedData_t fsStackData;
#elif USE_NEW
	SharedData_t * tsNewData = new SharedData_t();
	SharedData_t * fsNewData = new SharedData_t();
#elif USE_MMAP || USE_MMAP64
	int fd, fd2;
	SharedData_t * tsMmapData;
	SharedData_t * fsMmapData;
	int result;
	// ts mmap
	fd = open("./tmp_ts.txt", O_RDWR | O_CREAT | O_TRUNC, (mode_t)0600); 
	if (fd == -1) {
		perror("Error opening file for writing");
		exit(EXIT_FAILURE);
    	}
	result = lseek(fd, sizeof(SharedData_t) - 1, SEEK_SET);
    	if (result == -1) {
		close(fd);
		perror("Error calling lseek() to 'stretch' the file");
		exit(EXIT_FAILURE);
    	}

	result = write(fd, "", 1);
    	if (result != 1) {
		close(fd);
		perror("Error writing last byte of the file");
		exit(EXIT_FAILURE);
    	}	

	// fs map
	fd2 = open("./tmp_fs.txt", O_RDWR | O_CREAT | O_TRUNC, (mode_t)0600); 
	if (fd2 == -1) {
		perror("Error opening file for writing");
		exit(EXIT_FAILURE);
    	}
	result = lseek(fd2, sizeof(SharedData_t) - 1, SEEK_SET);
    	if (result == -1) {
		close(fd2);
		perror("Error calling lseek() to 'stretch' the file");
		exit(EXIT_FAILURE);
    	}

	result = write(fd2, "", 1);
    	if (result != 1) {
		close(fd2);
		perror("Error writing last byte of the file");
		exit(EXIT_FAILURE);
    	}	


#if USE_MMAP
	tsMmapData = (SharedData_t *) mmap(0, sizeof(SharedData_t), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    	if (tsMmapData == MAP_FAILED) {
		close(fd);
		perror("Error mmapping the file");
		exit(EXIT_FAILURE);
    	}


	fsMmapData = (SharedData_t *) mmap(0, sizeof(SharedData_t), PROT_READ | PROT_WRITE, MAP_SHARED, fd2, 0);
    	if (fsMmapData == MAP_FAILED) {
		close(fd2);
		perror("Error mmapping the file");
		exit(EXIT_FAILURE);
    	}

#elif USE_MMAP64

	tsMmapData = (SharedData_t *) mmap64(0, sizeof(SharedData_t), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    	if (tsMmapData == MAP_FAILED) {
		close(fd);
		perror("Error mmapping the file");
		exit(EXIT_FAILURE);
    	}


	fsMmapData = (SharedData_t *) mmap64(0, sizeof(SharedData_t), PROT_READ | PROT_WRITE, MAP_SHARED, fd2, 0);
    	if (fsMmapData == MAP_FAILED) {
		close(fd2);
		perror("Error mmapping the file");
		exit(EXIT_FAILURE);
    	}
#endif

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
#if USE_GLOBAL_DATA
		atomic<uint64_t> *tsGData = &tsGlobalData.data[0];
		atomic<uint64_t> *fsGData = &fsGlobalData.data[me];
		printf("tsGlobalData: %lx, tsGData: %lx\n", &tsGlobalData.dummy1[0], tsGData);
#elif USE_MALLOC
		atomic<uint64_t> *tsMData = &(tsMallocData->data[0]);
		atomic<uint64_t> *fsMData = &(fsMallocData->data[me]);
		printf("tsMallocData: %lx, tsMData: %lx\n", &tsMallocData->dummy1[0], tsMData);
		printf("fsMallocData: %lx, fsMData: %lx\n", &fsMallocData->dummy1[0], fsMData);
#elif USE_STACK
                atomic<uint64_t> *tsSData = &tsStackData.data[0];
                atomic<uint64_t> *fsSData = &fsStackData.data[me];
		printf("tsStackData: %lx, tsSData: %lx\n", &tsStackData.dummy1[0], tsSData);
#elif USE_CALLOC
                atomic<uint64_t> *tsCData = &(tsCallocData->data[0]);
                atomic<uint64_t> *fsCData = &(fsCallocData->data[me]);
		printf("tsCallocData: %lx, tsCData: %lx\n", &tsCallocData->dummy1[0], tsCData);
#elif USE_ALIGNED_ALLOC
                atomic<uint64_t> *tsAAData = &(tsAlignedAllocData->data[0]);
                atomic<uint64_t> *fsAAData = &(fsAlignedAllocData->data[me]);
		printf("tsAlignedAllocData: %lx, tsAAData: %lx\n", &tsAlignedAllocData->dummy1[0], tsAAData);
		printf("fsAlignedAllocData: %lx, fsAAData: %lx\n", &fsAlignedAllocData->dummy1[0], fsAAData);
#elif USE_REALLOC
                atomic<uint64_t> *tsRData = &(tsReallocData->data[0]);
                atomic<uint64_t> *fsRData = &(fsReallocData->data[me]);
		printf("tsReallocData: %lx, tsRData: %lx\n", &tsReallocData->dummy1[0], tsRData);
		printf("fsReallocData: %lx, fsRData: %lx\n", &fsReallocData->dummy1[0], fsRData);
#elif USE_MEMALIGN
                atomic<uint64_t> *tsMData = &(tsMemalignData->data[0]);
                atomic<uint64_t> *fsMData = &(fsMemalignData->data[me]);
		printf("tsMemalignData: %lx, tsMData: %lx\n", &tsMemalignData->dummy1[0], tsMData);
		printf("fsMemalignData: %lx, fsMData: %lx\n", &fsMemalignData->dummy1[0], fsMData);
#elif USE_POSIX_MEMALIGN
                atomic<uint64_t> *tsPMData = &(((SharedData_t *) tsPosixMemalignData)->data[0]);
                atomic<uint64_t> *fsPMData = &(((SharedData_t *) fsPosixMemalignData)->data[me]);
		printf("tsPosixMemalignData: %lx, tsPMData: %lx\n", &((SharedData_t *) tsPosixMemalignData)->dummy1[0], tsPMData);
		printf("fsPosixMemalignData: %lx, fsPMData: %lx\n", &((SharedData_t *) fsPosixMemalignData)->dummy1[0], fsPMData);
#elif USE_VALLOC
		atomic<uint64_t> *tsVData = &(tsVallocData->data[0]);
		atomic<uint64_t> *fsVData = &(fsVallocData->data[me]);
		printf("tsVallocData: %lx, tsVData: %lx\n", &tsVallocData->dummy1[0], tsVData);
		printf("fsVallocData: %lx, fsVData: %lx\n", &fsVallocData->dummy1[0], fsVData);
#elif USE_PVALLOC
		atomic<uint64_t> *tsPData = &(tsPvallocData->data[0]);
		atomic<uint64_t> *fsPData = &(fsPvallocData->data[me]);
		printf("tsPvallocData: %lx, tsPData: %lx\n", &tsPvallocData->dummy1[0], tsPData);
		printf("fsPvallocData: %lx, fsPData: %lx\n", &fsPvallocData->dummy1[0], fsPData);
#elif USE_NUMA_ALLOC_ONNODE
		atomic<uint64_t> *tsNAOData = &(tsNAOnnodeData->data[0]);
		atomic<uint64_t> *fsNAOData = &(fsNAOnnodeData->data[me]);
		printf("tsNAOnnodeData: %lx, tsNAOData: %lx\n", &tsNAOnnodeData->dummy1[0], tsNAOData);
		printf("fsNAOnnodeData: %lx, fsNAOData: %lx\n", &fsNAOnnodeData->dummy1[0], fsNAOData);
#elif USE_NUMA_ALLOC_INTERLEAVED
		atomic<uint64_t> *tsNAIData = &(tsNAInterleavedData->data[0]);
		atomic<uint64_t> *fsNAIData = &(fsNAInterleavedData->data[me]);
		printf("tsNAInterleavedData: %lx, tsNAIData: %lx\n", &tsNAInterleavedData->dummy1[0], tsNAIData);
		printf("fsNAInterleavedData: %lx, fsNAIData: %lx\n", &fsNAInterleavedData->dummy1[0], fsNAIData);
#elif USE_NEW
                atomic<uint64_t> *tsNData = &(tsNewData->data[0]);
                atomic<uint64_t> *fsNData = &(fsNewData->data[me]);
		printf("tsNewData: %lx, tsNData: %lx\n", &tsNewData->dummy1[0], tsNData);
		printf("fsNewData: %lx, fsNData: %lx\n", &fsNewData->dummy1[0], fsNData);
#elif USE_MMAP || USE_MMAP64
		atomic<uint64_t> *tsMpData = &(tsMmapData->data[0]);
                atomic<uint64_t> *fsMpData = &(fsMmapData->data[me]);
		printf("tsMmapData: %lx, tsMpData: %lx\n", &tsMmapData->dummy1[0], tsMpData);
		printf("fsMmapData: %lx, fsMpData: %lx\n", &fsMmapData->dummy1[0], fsMpData);
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
#elif USE_ALIGNED_ALLOC
                                        *tsAAData += rNum;
#elif USE_REALLOC
                                        *tsRData += rNum;
#elif USE_MEMALIGN
                                        *tsMData += rNum;
#elif USE_POSIX_MEMALIGN
                                        *tsPMData += rNum;
#elif USE_VALLOC
                                        *tsVData += rNum;
#elif USE_PVALLOC
                                        *tsPData += rNum;
#elif USE_NUMA_ALLOC_ONNODE
                                        *tsNAOData += rNum;
#elif USE_NUMA_ALLOC_INTERLEAVED
                                        *tsNAIData += rNum;
#elif USE_MMAP || USE_MMAP64
                                        *tsMpData += rNum;
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
#elif USE_ALIGNED_ALLOC
                                        *fsAAData += rNum;
#elif USE_REALLOC
                                        *fsRData += rNum;
#elif USE_MEMALIGN
                                        *fsMData += rNum;
#elif USE_POSIX_MEMALIGN
                                        *fsPMData += rNum;
#elif USE_VALLOC
                                        *fsVData += rNum;
#elif USE_PVALLOC
                                        *fsPData += rNum;
#elif USE_NUMA_ALLOC_ONNODE
                                        *fsNAOData += rNum;
#elif USE_NUMA_ALLOC_INTERLEAVED
                                        *fsNAIData += rNum;
#elif USE_MMAP || USE_MMAP64
                                        *fsMpData += rNum;
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
#elif USE_ALIGNED_ALLOC
                justToAvoidCompilerOptimization += *tsAAData;
                justToAvoidCompilerOptimization += *fsAAData;
#elif USE_REALLOC
                justToAvoidCompilerOptimization += *tsRData;
                justToAvoidCompilerOptimization += *fsRData;
#elif USE_MEMALIGN
                justToAvoidCompilerOptimization += *tsMData;
                justToAvoidCompilerOptimization += *fsMData;
#elif USE_POSIX_MEMALIGN
                justToAvoidCompilerOptimization += *tsPMData;
                justToAvoidCompilerOptimization += *fsPMData;
#elif USE_VALLOC
                justToAvoidCompilerOptimization += *tsVData;
                justToAvoidCompilerOptimization += *fsVData;
#elif USE_PVALLOC
                justToAvoidCompilerOptimization += *tsPData;
                justToAvoidCompilerOptimization += *fsPData;
#elif USE_NUMA_ALLOC_ONNODE
                justToAvoidCompilerOptimization += *tsNAOData;
                justToAvoidCompilerOptimization += *fsNAOData;
#elif USE_NUMA_ALLOC_INTERLEAVED
                justToAvoidCompilerOptimization += *tsNAIData;
                justToAvoidCompilerOptimization += *fsNAIData;
#elif USE_MMAP || USE_MMAP64
                justToAvoidCompilerOptimization += *tsMpData;
                justToAvoidCompilerOptimization += *fsMpData;
#else
                assert(0 && "NYI");
#endif		
		justToAvoidCompilerOptimization += *privateData;		
	}
#if USE_GLOBAL_DATA || USE_STACK
#elif USE_MALLOC
	free(tsMallocData);
	free(fsMallocData);
#elif USE_CALLOC
	free(tsCallocData);
	free(fsCallocData);
#elif USE_ALIGNED_ALLOC
	free(tsAlignedAllocData);
	free(fsAlignedAllocData);
#elif USE_NEW
	free(tsNewData);
	free(fsNewData);
#elif USE_REALLOC
	free(tsReallocData);
	free(fsReallocData);
#elif USE_MEMALIGN
	free(tsMemalignData);
	free(fsMemalignData);
#elif USE_POSIX_MEMALIGN
	free(tsPosixMemalignData);
	free(fsPosixMemalignData);
#elif USE_VALLOC
	free(tsVallocData);
	free(fsVallocData);
#elif USE_PVALLOC
	free(tsPvallocData);
	free(fsPvallocData);
#elif USE_NUMA_ALLOC_ONNODE
	numa_free(tsNAOnnodeData, sizeof(SharedData_t));
	numa_free(fsNAOnnodeData, sizeof(SharedData_t));
#elif USE_NUMA_ALLOC_INTERLEAVED
	numa_free(tsNAInterleavedData, sizeof(SharedData_t));
	numa_free(fsNAInterleavedData, sizeof(SharedData_t));
#elif USE_MMAP || USE_MMAP64
	if (munmap(tsMmapData, sizeof(SharedData_t)) == -1) {
		perror("Error un-mmapping the file");
		/* Decide here whether to close(fd) and exit() or not. Depends... */
    	}

    	/* Un-mmaping doesn't close the file, so we still need to do that.
     	*/
    	close(fd);

	if (munmap(fsMmapData, sizeof(SharedData_t)) == -1) {
		perror("Error un-mmapping the file");
		/* Decide here whether to close(fd) and exit() or not. Depends... */
    	}

    	/* Un-mmaping doesn't close the file, so we still need to do that.
     	*/
    	close(fd2);
#else
		assert(0 && "NYI");
#endif
	return justToAvoidCompilerOptimization.load() ^ justToAvoidCompilerOptimization.load();
}
