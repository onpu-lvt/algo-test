#include <stdio.h>
#include <stdlib.h>
#include "insert_sort.h"

void insert_sort(elem_t *arr, size_t length) 
{

	int i, j, temp;
	for (i = 1; i < length; i++) {
        		temp = arr[i];
        		for (j = i - 1; j >= 0; j--) {
                		if (arr[j] < temp) {
                        			break;
                		}
                	arr[j+1] = arr[j];
        		}
        	arr[j+1] = temp;
	}
}