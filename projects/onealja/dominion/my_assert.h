#include <stdlib.h>

void assert(int val) 
{
   if (val)
      printf("PASSED\n");
   else
      printf("FAILED\n");
}
