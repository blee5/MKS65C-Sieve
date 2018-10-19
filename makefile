all:
	gcc -o p.out sieve.c driver.c -lm -g

run: all
	time ./p.out 1000000 10
	time ./p.out 10000000 10
