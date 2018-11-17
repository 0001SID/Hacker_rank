#include <stdio.h>
int main()
{
    int a = 7;
    int remain = 1,sum;
  sum = ((a + (a - (remain -1)))*((remain-1)/2)) + (a - (remain-1)/2);
                printf("odd sum = %d",sum);
   sum = (a + (a - (remain -1)))*(remain/2);
    printf("even sum = %d ",sum);
   return 0;
}