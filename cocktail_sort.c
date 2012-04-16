#include <stdio.h>
#include <stdlib.h>
#include "cocktail_sort.h"
#define SWAP(A,B) {A=A^B; B=A^B; A=A^B;}

void cocktail_sort(elem_t *mas, size_t length) 
{
        int last = length-1, left = 1, right = length-1, j;
 
        do {
                for(j = right; j >= left; j--) {
                        if(mas[j-1] > mas[j]) {
                                SWAP(mas[j-1], mas[j]);
                                last = j;
                        }
                }
 
                left = last + 1;
 
                for(j = left; j <= right; j++) {
                        if(mas[j-1] > mas[j]) {
                                SWAP(mas[j-1], mas[j]);
                                last = j;
                        }
                }
 	  right = last-1;
 
           } while(left < right);
}

