#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    char * temp = malloc(n*sizeof(int));
    char * psn = malloc(n*sizeof(char));
    scanf("%s",temp);
    for(int i = 0; i< n; i++)
    {
        if(temp[i] == 'D')
        psn[i] = -1;
        else
        psn [i] = 1;
    }
    int count=0,ud[2]={0},valy=0;
    static int state = 0;
    for (int i = 0; i < n; i++)
    {
        count += psn[i];
        if (count == 0)
        {
            for (int j = state; j <= i; j++)
            {
                if (j <= state + ((i - state+1) / 2 - 1))
                {
                    ud[0] += psn[j];
                }
                else
                {
                    ud[1] += psn[j];
                }
            }
            if (ud[0] < ud[1])
            {
                valy++;
            }
            state = i + 1;
            count = 0;
            memset(ud,0,2*sizeof(ud));
        }
    }
    printf("%d", valy);
    free(temp);
    free(psn);
    return 0;
}