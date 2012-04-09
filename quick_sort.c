#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "quick_sort.h"

/**
 * Checks array bounds in quicksort()
 */
#define CHECK_QS_BND(COND, IND, LEN) \
	(assert(IND < LEN), COND)
/* #define CHECK_QS_BND(COND, IND, LEN) \ */
/* 	(COND) */

void quick_sort(elem_t *arr, size_t length) 	
{

  	long i = 0, j = length;
  	int temp, p;

	printf("quick_sort: %lu, %d, %lu\n", length, (int)(length>>1), length>>1);

  	p = arr[ length>>1 ]; 

  	do {
    		while CHECK_QS_BND(( arr[i] < p ), i, length) i++;
		while CHECK_QS_BND(( arr[j] > p ), j, length) j--;
		if (i <= j) {
			temp = arr[i]; 
			arr[i] = arr[j]; 
			arr[j] = temp;
			i++; j--;
		}
  	} while ( i<=j );

  	if ( j > 0 ) {
		quick_sort(arr, j);
	}
  	if ( length > i ) {
		quick_sort(arr+i, length-i);
 	}
}
