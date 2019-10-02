all: ubench

ubench_write: ubench.cpp util.cpp
	g++ -fopenmp  -DUSE_ATOMIC_WRITE ubench.cpp -std=c++11 -O2 -o ubench_write -g
	
ubench_add: ubench.cpp util.cpp
	g++ -fopenmp  -DUSE_ATOMIC_ADD ubench.cpp -std=c++11 -O2 -o ubench_add -g

ubench_exchg: ubench.cpp util.cpp
	g++ -fopenmp  -DUSE_ATOMIC_EXCHG ubench.cpp -std=c++11 -O2 -o ubench_exchg -g

clean:
	rm ubench_*
