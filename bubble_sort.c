#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"

void bubble_sort(elem_t *b, size_t length)
{
  int i, j, tmp;
  for(i = 0 ; i < length ; i++)
    {
      for(j = i ; j < length ; j++)
	{
	  if(b[i] > b[j])
	    {
	      tmp = b[i];
	      b[i] = b[j];
	      b[j] = tmp;
	    }
	}
    }
}
