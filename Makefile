CC=gcc
FLAGS=-g -std=c99 -Wall
TGT=a-test

all:
	$(CC) $(FLAGS) \
	merge_sort.c  quick_sort.c  test_sort.c bubble_sort.c \
	-o $(TGT)

clean:
	rm -rf $(TGT)
	rm -rf *.dat

bubble:
	./a-test | grep bubble_sort | sed 's/bubble_sort://' | \
	sed 's/size=//' | sed 's/time=//' > bubble_sort.dat
	gnuplot bubble_sort.gp
