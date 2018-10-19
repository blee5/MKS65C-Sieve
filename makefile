all:
	gcc -o p.out sieve.c driver.c -lm -g

run: all
	time -p ./p.out 1000000 10

long: all
	time -p ./p.out 1000000 10
	time -p ./p.out 10000000 10

single: all
	time -p ./p.out
