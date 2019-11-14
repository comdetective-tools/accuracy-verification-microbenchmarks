all: ubench

ubench: ubench.cpp util.cpp
	g++ -fopenmp ubench.cpp -std=c++11 -O2 -o ubench -g
	

clean:
	rm ubench
