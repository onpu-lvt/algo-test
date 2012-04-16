CC=gcc
FLAGS=-O2 -std=c99 -Wall
TGT=a-test

all:
	$(CC) $(FLAGS) \
	bubble_sort.c merge_sort.c  quick_sort.c  test_sort.c radix_sort.c \
	-o $(TGT)

clean:
	rm -rf $(TGT)
	rm -rf *.dat
	rm -rf *.png

bubble:
	./a-test | grep bubble_sort | sed 's/bubble_sort://' | \
	sed 's/size=//' | sed 's/time=//' > bubble_sort.dat
	gnuplot bubble_sort.gp

radix:
	./a-test | grep radix_sort | sed 's/radix_sort://' | \
	sed 's/size=//' | sed 's/time=//' > radix_sort.dat
	gnuplot radix_sort.gp
