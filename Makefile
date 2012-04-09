CC=gcc
FLAGS=-O2 -std=c99 -Wall
TGT=a-test

all:
	$(CC) $(FLAGS) \
	merge_sort.c  quick_sort.c  test_sort.c bubble_sort.c  insert_sort.c  	shell_sort.c  cocktail_sort.c \
	-o $(TGT)

clean:
	rm -rf $(TGT)
	rm -rf *.dat
	rm -rf *.png

bubble:
	./a-test | grep bubble_sort | sed 's/bubble_sort://' | \
	sed 's/size=//' | sed 's/time=//' > bubble_sort.dat
	gnuplot bubble_sort.gp

quick:
	./a-test | grep quick_sort | sed 's/quick_sort://' | \
	sed 's/size=//' | sed 's/time=//' > quick_sort.dat
	gnuplot quick_sort.gp

insert:
	./a-test | grep insert_sort | sed 's/insert_sort://' | \
	sed 's/size=//' | sed 's/time=//' > insert_sort.dat
	gnuplot insert_sort.gp

shell:
	./a-test | grep shell_sort | sed 's/shell_sort://' | \
	sed 's/size=//' | sed 's/time=//' > shell_sort.dat
	gnuplot shell_sort.gp

cocktail:
	./a-test | grep cocktail_sort | sed 's/cocktail_sort://' | \
	sed 's/size=//' | sed 's/time=//' > cocktail_sort.dat
	gnuplot cocktail_sort.gp


