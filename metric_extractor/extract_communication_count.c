#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef DEBUG
#define INITIAL_ALLOC 2
#else
#define INITIAL_ALLOC 512
#endif

#define INTER_CORE_ALL_SHARING 0
#define INTER_THREAD_ALL_SHARING 1
#define INTER_CORE_TRUE_SHARING 2
#define INTER_THREAD_TRUE_SHARING 3
#define INTER_CORE_FALSE_SHARING 4
#define INTER_THREAD_FALSE_SHARING 5
#define ALL_RFO 6

void extract_all_rfo_count(char *line, char all_rfo_count[100]) {
	char all_rfo_str[10];
	//char all_rfo_count[100];
	sscanf(line, "%s \t%s \t\n", all_rfo_count, all_rfo_str);
}

double extract_communication_count(char *line, int communication_type)
{
    char comdetective[20], stats[10], fs_volume_str[20], fs_core_volume_str[20], ts_volume_str[20], ts_core_volume_str[20], as_volume_str[20], as_core_volume_str[20], cache_line_transfer_str[25], cache_line_transfer_millions_str[30], cache_line_transfer_gbytes_str[30];
    double fs_volume_count, fs_core_volume_count, ts_volume_count, ts_core_volume_count, as_volume_count, as_core_volume_count, cache_line_transfer_count, cache_line_transfer_millions_count, cache_line_transfer_gbytes_count;
    sscanf(line, "%*[^0123456789.]%lf %*[^0123456789.]%lf %*[^0123456789.]%lf %*[^0123456789.]%lf %*[^0123456789.]%lf %*[^0123456789.]%lf %*[^0123456789.]%lf %*[^0123456789.]%lf %*[^0123456789.]%lf\n", &fs_volume_count, &fs_core_volume_count, &ts_volume_count, &ts_core_volume_count, &as_volume_count, &as_core_volume_count, &cache_line_transfer_count, &cache_line_transfer_millions_count, &cache_line_transfer_gbytes_count);
    if(communication_type == INTER_CORE_ALL_SHARING)
    	return cache_line_transfer_count;
    if(communication_type == INTER_THREAD_ALL_SHARING)
	return as_volume_count;
    if(communication_type == INTER_CORE_TRUE_SHARING)
    	return ts_core_volume_count;
    if(communication_type == INTER_THREAD_TRUE_SHARING)
	return ts_volume_count; 
    if(communication_type == INTER_CORE_FALSE_SHARING)
    	return fs_core_volume_count;
    if(communication_type == INTER_THREAD_FALSE_SHARING)
	return fs_volume_count; 
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

void removeChar(char str[100], char garbage) {

    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != garbage) dst++;
    }
    *dst = '\0';
}

int
main(int argc, char *argv[]) {
    FILE *fin;
    char *line;
    char comdetective_stats[20] = "COMDETECTIVE STATS:";
    char all_rfo_str[10] = "r430864";
    if ( argc != 3 ) {
        return EXIT_FAILURE;
    }
    fin = fopen(argv[1], "r");
    int communication_type = atoi(argv[2]);

    if ( fin ) {
	int i = 0;
	int j = 0;
	if(communication_type == ALL_RFO) {
		while ( line = read_line(fin) ) {
            		if ( strstr(line, all_rfo_str) ){
				char num[100];
				extract_all_rfo_count(line, num);
				removeChar(num, '.');
				printf("%s\n", num);
            		}
            		free(line);
        	}
	} else {
        	while ( line = read_line(fin) ) {
            		if ( strstr(line, comdetective_stats) ){
				double d = extract_communication_count(line, communication_type);
				printf("%0.2lf\n", d);
            		}
            		free(line);
		}
        }
    }

    fclose(fin);
    return 0;
}
