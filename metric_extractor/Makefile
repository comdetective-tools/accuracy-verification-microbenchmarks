all: extract_communication_count extract_overhead

extract_communication_count: extract_communication_count.c
	gcc extract_communication_count.c -O2 -o extract_communication_count

extract_overhead: extract_overhead.c
	gcc extract_overhead.c -O2 -o extract_overhead

clean:
	rm extract_overhead extract_communication_count
