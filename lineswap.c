#include <stdio.h>
#include<stdlib.h>
#include<string.h>
void check(int *a, int n)
{
    int serial[n], count = 0;
    for (int i = 0; i < n; i++)
    {
        serial[i] = i + 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (serial[i] != *(a + i))
        {
            if (abs((serial[i] - *(a + i))) > 2)
            {
                printf("Too chaotic");
                count = 0;
                break;
            }
            else
            {
                count += abs(serial[i] - *(a + i));
            }
        }
    }
    if(count !=0) printf("%d",count/2);
}
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int i = 0; i< tc; i++)
    {
        int prsn;
        scanf("%d",&prsn);
        int line[prsn];
        for(int j = 0; j<prsn; j++)
        {
            scanf("%d",&line[j]);
        }
        check(line,prsn);
        printf("\n");
        memset(line,0,sizeof(line));
    }

    return 0;
}