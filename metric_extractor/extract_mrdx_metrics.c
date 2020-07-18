#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef DEBUG
#define INITIAL_ALLOC 2
#else
#define INITIAL_ALLOC 512
#endif

#define INTER_THREAD_ALL_SHARING 0
#define INTER_THREAD_INVALIDATION 1
#define RFO_MISS 2

long extract_rfo_miss_count(char *line) {
	char rfo_miss_str[10];
	long rfo_miss_count;
	sscanf(line, "%*[^0123456789]%ld \t%s \t\n", &rfo_miss_count, rfo_miss_str);
	return rfo_miss_count;
}

double extract_mrdx_metric(char *line, int metric_type)
{
    char as_volume_str[20], invalidation_volume_str[20];
    double as_volume_count, invalidation_volume_count;
    sscanf(line, "%*[^0123456789.]%lf %*[^0123456789.]%lf\n", &as_volume_count, &invalidation_volume_count);
    if(metric_type == INTER_THREAD_ALL_SHARING)
    	return as_volume_count;
    if(metric_type == INTER_THREAD_INVALIDATION)
	return invalidation_volume_count;
    return -1;
}

char *
read_line(FILE *fin) {
    char *buffer;
    char *tmp;
    int read_chars = 0;
    int bufsize = INITIAL_ALLOC;
    char *line = malloc(bufsize);

    if ( !line ) {
        return NULL;
    }

    buffer = line;

    while ( fgets(buffer, bufsize - read_chars, fin) ) {
        read_chars = strlen(line);

        if ( line[read_chars - 1] == '\n' ) {
            line[read_chars - 1] = '\0';
            return line;
        }

        else {
            bufsize = 2 * bufsize;
            tmp = realloc(line, bufsize);
            if ( tmp ) {
                line = tmp;
                buffer = line + read_chars;
            }
            else {
                free(line);
                return NULL;
            }
        }
    }
    return NULL;
}

int
main(int argc, char *argv[]) {
    FILE *fin;
    char *line;
    char comdetective_stats[20] = "MRDX STATS:";
    char rfo_miss_str[10] = "r2224";
    if ( argc != 3 ) {
        return EXIT_FAILURE;
    }
    fin = fopen(argv[1], "r");
    int metric_type = atoi(argv[2]);

    if ( fin ) {
	int i = 0;
	int j = 0;
	if(metric_type == RFO_MISS) {
		while ( line = read_line(fin) ) {
            		if ( strstr(line, rfo_miss_str) ){
				long d = extract_rfo_miss_count(line);
				printf("%ld\n", d);
            		}
            		free(line);
        	}
	} else {
        	while ( line = read_line(fin) ) {
            		if ( strstr(line, comdetective_stats) ){
				double d = extract_mrdx_metric(line, metric_type);
				printf("%0.2lf\n", d);
            		}
            		free(line);
		}
        }
    }

    fclose(fin);
    return 0;
}
