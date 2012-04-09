#include <stdio.h>
#include <stdlib.h>
#include "quick_sort.h"

void quick_sort(elem_t *arr, size_t length) 	
{

  	long i = 0, j = length;
  	int temp, p;
  	p = arr[ length>>1 ]; 

  	do {
    		while ( arr[i] < p ) i++;
    			while ( arr[j] > p ) j--;
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
