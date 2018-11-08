#include<stdio.h>
#include<conio.h>
int main()
{
    int *p[3],a = 5,b = 6,c = 7,i;
    p[0] = &a;
    p[1] = &b;
    p[2] = &c;
    for(i = 0; i < 3; i++)
    {
        printf("Address in p[%d] = %u\n",i,p[i]);
        printf("Value in p[%d] = %d\n",i,*p[i]);
    }
    getch();
    return 0;
    suman das
}