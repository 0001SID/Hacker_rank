#include<stdio.h>
int main()
{
    int a,b,temp;
    scanf("%d %d",&a,&b);
    int num[a];
    for(int i = 0 ; i < a; i++)
    {
        scanf("%d ",&num[i]);
    }
    
    for(int i = 0 ; i< b; i++)
    {
        temp = num[0];
        for(int j = 0 ; j < a; j++)
        {
            if(j == a-1) num[j] = temp;
            else
            num[j] = num[j+1];
            if(i == b-1)
            {
                printf("%d ",num[j]);
            }
        }
    }

}