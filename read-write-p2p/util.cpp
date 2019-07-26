#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<omp.h>
#include<stdint.h>
#include<atomic>

using namespace std;

void ParseArg(int argc, char ** argv, int& nIter, int& nGroups, int& nThreads, float * &shareFrac, int * &groupMarker, float * &readFrac, int * &threadList) {
	extern char *optarg;
	extern int optind;
	nIter = -1;
	nGroups = -1;
	nThreads = -1;
	char c;
	int * groupDelimiter;
	int delimiterFlag = 0;
	/*ubench -g 4 -n 16 -s 0.2 0.3 0.1 0.5 -d 3 5 4 4 -t 0 1 2 3 4 5 6 8 9 10 7 11 12 13 14 15 -i 1000000 */

	static char usage[] = "usage: %s -g numberOfThreadGroups -n numberOfThreads -s sharingFractionList -d threadGroupDelimiterList -t threadList [-t threadList] -i numIters\n";
	while ((c = getopt(argc, argv, "g:n:s:d:t:r:i:")) != -1) {
	  int index = -1;
	  int i;
		switch (c) {
		case 'g':
			nGroups = atol(optarg);
			shareFrac = (float *) malloc (nGroups * sizeof(float));
			groupDelimiter = (int *) malloc (nGroups * sizeof(int));
			delimiterFlag = 1;
			break;
		case 'n':
			nThreads = atol(optarg);
			threadList = (int *) malloc (nThreads * sizeof(int));
			groupMarker = (int *) malloc (nThreads * sizeof(int));
			readFrac = (float *) calloc (nThreads, sizeof(float));
			break;
		case 's':
			index = optind-1;
			i = 0;
			while (i < nGroups) {
		        	shareFrac[i++] = 100 * atof(argv[index]);
				index++;
			}
			break;
		case 'd':
			index = optind-1;
			i = 0;
			while (i < nGroups) {
		        	groupDelimiter[i++] = atoi(argv[index]);
				index++;
			}
			break;
		case 't':
		        index = optind-1;
			i = 0;
			while (i < nThreads) {
				int tid = atoi(argv[index]);
		        	threadList[tid] = i++; 
				index++;
			}
			break;
		
		case 'r':
		        index = optind-1;
			i = 0;
			while (i < nThreads) {
		        	readFrac[i++] = 100 * atof(argv[index]);
				index++;
			}
			break;

		case 'i':
			nIter = atol(optarg);
			break;
		case 'h':
		default:
			fprintf(stderr, usage, argv[0]);
			exit(-1);
			break;
		}
	}

	int i = 0;
	int k = 0;
	while (i < nGroups) {
		int j = 0;
		while (j < groupDelimiter[i]) {
			groupMarker[k] = i;
			k++;
			j++;
		}
		i++;
	}
	if(nGroups > 0)
		free(groupDelimiter);
/*
nIter = -1;
	nGroups = -1;
	nThreads = -1;
*/
	if (argc < 10 || nIter < 0 || nGroups < 0 || nThreads == -1) {
        	fprintf(stderr, usage, argv[0]);
        	exit(-1);
	} 
}
