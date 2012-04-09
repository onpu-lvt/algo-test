#include <stdio.h>
#include <stdlib.h>
#include "shell_sort.h"

void shell_sort(elem_t *arr, size_t length) 
{
 	int i, inc, k, j, seq[40];
   	int p1, p2, p3, s;
 
 	p1 = p2 = p3 = 1;
 	s = -1;
 	do {
  		if (++s % 2) {
   			seq[s] = 8*p1 - 6*p2 + 1;
  		}
  			else {
   				seq[s] = 9*p1 - 9*p3 + 1;
   				p2 *= 2;
   				p3 *= 2;
  			}
  		p1 *= 2;
 	}
 	while(3*seq[s] < length);  
 
	k = s > 0 ? --s : 0;

	while (k >= 0) {
  		inc = seq[k--];
  		for (i = inc; i < length; i++) {
   			int temp = arr[i];
   				for (j = i-inc; (j >= 0) && (arr[j] > temp); j -= inc) {
    					arr[j+inc] = arr[j];
   				}
   			arr[j+inc] = temp;
  		}
 	}
}