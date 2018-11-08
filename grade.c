#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int num[n];
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&num[i]);
    }
    for(int i = 0 ; i<n; i++)
    {
        (num[i]<38)?printf("%d\n",num[i]):(num[i]%5 >2)?printf("%d\n",(num[i] +5-num[i]%5)):printf("%d\n",num[i]);
    }
    return 0;
}