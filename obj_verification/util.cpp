#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<omp.h>
#include<stdint.h>
#include<atomic>

using namespace std;

void ParseArg(int argc, char ** argv, int &nThreads, float &shareFrac, float &falseShareFrac, uint64_t &nIter){
	extern char *optarg;
	extern int optind;
	nThreads = -1;
	shareFrac = -1;
	falseShareFrac = -1;
	nIter = -1;
	char c;
	static char usage[] = "usage: %s -n num_threads (2-8) -s sharing_to_non_sharing_ratio -f false_to_true_sharing_ratio -i num_iters\n";
	while ((c = getopt(argc, argv, "n:s:f:i:")) != -1) {
		switch (c) {
		case 'n':
			nThreads = atoi(optarg);
			break;
		case 's':
			shareFrac = 100 - 100 * atof(optarg);
			break;
		case 'f':
			falseShareFrac = 100 - 100 * atof(optarg);
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
	if (nThreads == -1 || shareFrac < 0 || falseShareFrac < 0 || nIter == -1) {
        	fprintf(stderr, usage, argv[0]);
        	exit(-1);
	} 
}
