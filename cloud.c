#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,count=0;
    scanf("%d",&n);
    int *cld = malloc(n*sizeof(int));
    for(int i =0 ; i< n ; i++)
    {
        scanf("%d",&cld[i]);
    }
    for(int i = 0; i< n-1 ;)
    {
        if(cld[i+2] == 0)
        {
            count++;
            i += 2;
        }
        else
        {
            count++;
            i+=1;
        }
    }
    printf("%d",count);
    return 0;
}