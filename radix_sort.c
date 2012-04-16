#include <stdio.h>
#include <stdlib.h>
#include "radix_sort.h"

void radix_sort(elem_t *b, size_t length)
{

  int dest[length], count[16], count2[16], tmp, i, j;
  
  for (j = 0; j < sizeof(int)*8; j+=4) {
    
    for (i = 0; i < 16; i++) {
    
      count[i] = 0;
      count2[i] = 0;
        
    }
      
      
    for (i = 0; i < length; i++) {
	
      count[(b[i] >> j) & 0x0F]++;
	
    }
      
    for (i = 1; i < 16; i++) {
	  
      count2[i] = count2[i-1] + count[i-1];
	
    }
      
            
    for (i = 0; i < length; i++) {
      
      tmp = (b[i] >> j) &0x0F;
      dest[count2[tmp]] = b[i];
      count2[tmp]++;
	
    }
      
    for (i = 0; i < length; i++) {

      b[i] = dest[i];
            
    }
      
  
  }
  
  
}
