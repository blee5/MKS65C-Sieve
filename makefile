all:
	gcc -o p.out sieve.c driver.c -lm -g

run: all
	time ./p.out 1000000 10
