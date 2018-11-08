#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n,num;
    scanf("%d", &n);
  	for(int i = 1; i <= n*2-1;i++)
      {
          for(int j = 0;j<n*2-1;j++)
          {
              if(i<=n)
              {
                if(j<i)
                {
                    num = n-j;
                }
                else if(j >= n*2-i)
                {
                    num = num+1;
                }
              }
             if(i>n)
             {
                 if(j<n-(i-n))
                 {
                     num = n-j;
                 }
                 else if(j >(n*2-1)-(n*2-i))
                 {
                     num = num+1;
                 }
             }
             printf("%d ",num);

          }
          printf("\n");
      }

    return 0;
}