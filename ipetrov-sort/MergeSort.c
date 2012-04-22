#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void doFill(int *arr, unsigned int size);
void doPrint(int *arr, unsigned int size);
long long getTimeUS();

void mergeSort(int *arr, unsigned int size);
void mSort(int *arr, unsigned int from, unsigned int to);
void mMerge(int *arr, unsigned int lFrom, unsigned int lTo, unsigned int rFrom, unsigned int rTo);

unsigned int sizes[] = {512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144};
unsigned int N = 10;
long long timeMeasure = 0, finalTime = 0;

int main() {
	int length = sizeof(sizes)/sizeof(int);
	int i = 0, j = 0;
	for(i = 0; i < length; i++) {
		timeMeasure = 0;
		finalTime = 0;
		unsigned int size = sizes[i];
		int wAr[size];
		for(j = 0; j < N; j++) {
			doFill(wAr, size);
			timeMeasure = -getTimeUS();
			mergeSort(wAr, size);
			timeMeasure += getTimeUS();
			finalTime += timeMeasure;
		}
		printf("\t%7d\t%lld\n", size, (finalTime/(N*1000)));
	}
}

void doFill(int *arr, unsigned int size) {
	int i = 0;
	for(i = 0; i < size; i++) {
		arr[i] = rand() % (size*10);
	}
}

void doPrint(int *arr, unsigned int size) {
	int i = 0;
	for(i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

long long getTimeUS() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (long long) tv.tv_sec * 1000000L + (long long) tv.tv_usec;
}

void  mergeSort(int *arr, unsigned int size) {
	mSort(arr, 0, size - 1);
}

void mSort(int *arr, unsigned int from, unsigned int to) {
	unsigned int middle = (from + to) / 2;
	if(from != middle && (middle + 1) != to) {
		mSort(arr, from, middle);
		mSort(arr, middle + 1, to);
	}
	mMerge(arr, from, middle, middle + 1, to);
}

void mMerge(int *arr, unsigned int lFrom, unsigned int lTo, unsigned int rFrom, unsigned int rTo) {
	int tmp = 0;
	if(lFrom == lTo && rFrom == rTo) {
		if(arr[lFrom] > arr[rFrom]) {
			tmp = arr[lFrom];
			arr[lFrom] = arr[rFrom];
			arr[rFrom] = tmp;
		}
		return;
	}

	int x = lFrom, y = rFrom;
	int z = 0;

	int tmpArr[rTo - lFrom + 1];

	do {
		if(arr[x] > arr[y]) {
			tmpArr[z] = arr[y];
			y++; z++;
		} else {
			tmpArr[z] = arr[x];
			x++; z++;
		}
	} while(x <= lTo && y <= rTo);

	x--; y--;

	if(x == lTo) {
		y++;
		for(; y <= rTo; y++, z++) {
			tmpArr[z] = arr[y];
		}
	} else {
		x++;
		for(; x <= lTo; x++, z++) {
			tmpArr[z] = arr[x];
		}
	}

	for(x = lFrom, z = 0; x <= rTo; x++, z++) {
		arr[x] = tmpArr[z];
	}
}
