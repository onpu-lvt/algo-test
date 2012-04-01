CC=gcc
FLAGS=-O3 -c99 -Wall
TGT=a-test

all:
	$(CC) $(FLAGS) \
	merge_sort.c  quick_sort.c  test_sort.c \
	-o $(TGT)

clean:
	rm -rf $(TGT)
