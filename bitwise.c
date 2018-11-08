#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int, int);

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
void calculate_the_maximum(int n,int k)
{
    static int fand,finalor,fxor,or,and,xor,o,x;
    for(int s = 1;s <= n;s++)
    {
        //and operator
        for (int a = s+1;a <=n;a++)
        {
            and = s&a;
            if(and <k &&and >fand)
            {
                fand = and;
            }

        }
        for (o = s+1;o <= n;o++)
        {
            or = s|o;
            if(or<k && or > finalor)
            {
                finalor = or;
            }
        }
        for (x = s+1;x <=n;x++)
        {
            xor = s^x;
            if(xor<k && xor >fxor)
            {
                fxor = xor;
            }
        }
    }
    printf("%d\n%d\n%d",fand,finalor,fxor );
}
