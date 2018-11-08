#include<stdio.h>
#include<stdlib.h>
int main()
{
    int sum = 0,n;
    scanf("%d",&n);
    int num[n];
    for(int i = 0;i < n; i++)
    {
        scanf("%d",&num[i]);
        sum += num[i];
    }
    printf("%d",sum);
}