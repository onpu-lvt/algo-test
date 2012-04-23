#include <stdio.h>
#include <stdlib.h>
#include "merge_sort.h"

static void mMerge(int *arr, unsigned int lFrom, unsigned int lTo, unsigned int rFrom, unsigned int rTo);
static void mSort(int *arr, unsigned int from, unsigned int to);

void merge_sort(elem_t *b, size_t length)
{
	mSort(b, 0, length - 1);
}

static void mSort(int *arr, unsigned int from, unsigned int to)
{
	unsigned int middle = (from + to) / 2;
	if(from != middle && (middle + 1) != to) {
		mSort(arr, from, middle);
		mSort(arr, middle + 1, to);
	}
	mMerge(arr, from, middle, middle + 1, to);
}

static void mMerge(int *arr, unsigned int lFrom, unsigned int lTo, unsigned int rFrom, unsigned int rTo)
{
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
