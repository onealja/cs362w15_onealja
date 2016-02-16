#include <stdlib.h>

int assert(int val) 
{
   if (val){
      printf("PASSED\n");
      return 0;
   }
   else{
      printf("FAILED\n");
      return 1;
   }
}
