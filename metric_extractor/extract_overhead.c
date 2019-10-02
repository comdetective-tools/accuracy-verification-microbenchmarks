#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef DEBUG
#define INITIAL_ALLOC 2
#else
#define INITIAL_ALLOC 512
#endif

double extract_overhead(char *line, int overhead_type)
{
    double elapsed_time, system_time, user_time, memory_overhead;
    sscanf(line, "%*[^0123456789.]%lf %*[^0123456789.]%lf %*[^0123456789.]%lf %*[^0123456789.]%lf\n", &elapsed_time, &system_time, &user_time, &memory_overhead);
    if(overhead_type == 1)
    	return memory_overhead;
    if(overhead_type == 0)
    	return elapsed_time;
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
    char elapsed_time_str[20] = "Elapsed Time";
    if ( argc != 3 ) {
        return EXIT_FAILURE;
    }
    fin = fopen(argv[1], "r");
    int overhead_type = atoi(argv[2]);

    if ( fin ) {
	int i = 0;
	int j = 0;
        while ( line = read_line(fin) ) {
            if ( strstr(line, elapsed_time_str) ){
		double d = extract_overhead(line, overhead_type);
		printf("%0.2lf\n", d);
            }
            free(line);
        }
    }

    fclose(fin);
    return 0;
}
