#include <stdio.h>
int ck(int clr[], int n)
{
    int check = 0, count = 0, rep;
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < i; k++)
        {
            if (clr[i] == clr[k])
            {
                rep = 1;
                break;
            }
        }
        if (rep != 1)
        {
            for (int j = 0; j < n; j++)
            {
                if (clr[i] == clr[j])
                {
                    check++;
                }
            }
        }
        // printf("check %d", check);
        count += check / 2;
        // printf("count %d ", count);
        check = 0,rep = 0;
    }
    return count;
}
int main()
{
    int n;
    scanf("%d", &n);
    int clr[n], pair;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &clr[i]);
    }
    pair = ck(clr, n);
    printf("%d", pair);
    return 0;
}