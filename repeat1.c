#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char s[100];
    long int n,count = 0;
    scanf("%s",&s);
    scanf("%ld",&n);
    for(int i = 0; i< strlen(s);i++)
    {
        if(s[i] == 'a')
        count++;
    }
    count = count * (n/strlen(s));
    for(int i = 0; i < n%strlen(s);i++)
    {
        if(s[i] == 'a')
        count++;
    }
    printf("%ld",count);
    return 0;
}