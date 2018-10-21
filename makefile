SHELL := /bin/bash

all:
	gcc -o p.out sieve.c driver.c -lm -g

run: all
	time ./p.out 1000000 10

long: all
	time ./p.out 1000000 10
	time ./p.out 10000000 10

single: all
	time ./p.out

profile:
	gcc sieve.c driver.c -lm -o p.out -g -pg && ./p.out 1000000 10 && gprof p.out -bl > prof

clean:
	rm *.out
	rm prof
