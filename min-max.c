#include<stdio.h>
int main()
{
    long int num[5],min[4],max[4],sum[2] = {0};
    for(int i = 0; i<5; i++)
    {
        scanf("%ld",&num[i]);
    }
    min[0] = num[0];
    max[0] = num[0];
    
    for(int j = 0; j<4; j++)
    {
        if(j>0)
        {
        min[j] = max[0];
        max[j] = min[0];
        }
        for(int i = 0; i < 5; i++)
        {
            if(j ==0)
            {
                if (num[i]<min[0])
                {
                    min[0] = num[i];
                }
                if(num[i] > max[0])
                {
                    max[0] = num[i];
                }

            }
            else
            {
               if((num[i]<min[j]) &&(num[i]>min[j-1]) ) 
               {
                   min[j] = num[i];
               }
               if((num[i]>max[j]) && (num[i]<max[j-1]))
               {
                   max[j] = num[i];
               }
            }
        }
    }
    for(int i = 0 ; i<4; i++)
    {
        sum[0] += min[i];
        sum[1] += max[i];
    }
    printf("%ld %ld",sum[0],sum[1]);
    return 0;
}