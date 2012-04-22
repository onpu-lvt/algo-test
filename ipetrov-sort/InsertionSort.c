#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void willFill(int *arr, unsigned int size);
void willPrint(int *arr, unsigned int size);
void doSort(int * arr, unsigned int size);
long long getTimeUS(void);

unsigned int sizes[] = {100, 500, 1000, 5000, 10000, 15000, 20000, 25000, 30000, 50000, 60000, 75000, 100000, 150000, 200000};

int i = 0, j = 0, x = 0, y = 0, z = 0, N = 10;
long long timeMeasure = 0, finalTime = 0;

int main(){
	int length = sizeof(sizes) / sizeof(int);
	for(x = 0; x < length; x++) {
		timeMeasure = 0;
		finalTime = 0;
		unsigned int size = sizes[x];
		int wAr[size];
		for(y = 0; y < N; y++) {
			willFill(wAr, size);
			timeMeasure = -getTimeUS();
			doSort(wAr, size);
			timeMeasure += getTimeUS();
			finalTime += timeMeasure;
		}
		printf("\t%7d\t%lld\n", size, (finalTime/(N*1000)));
	}
}

void willFill(int *arr, unsigned int size) {
	for(i = 0; i < size; i++) {
		arr[i] = rand()%size*10;
	}
}

void willPrint(int *arr, unsigned int size) {
	for(i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}


void doSort(int *arr, unsigned int size) {
	int key = 0, tmp = 0;
	j = 0;
	for(i = 1; i < size; i++) {
		key = arr[i];
		j = i - 1;
		while(j > 0 && key < arr[j]) {
			tmp = arr[j+1];
			arr[j+1] = arr[j];
			arr[j] = tmp;
			j--;
		}
	}
}

long long getTimeUS() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (long long) tv.tv_sec * 1000000L + (long long) tv.tv_usec;
}
