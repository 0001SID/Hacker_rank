#include <stdio.h>
#include <stdlib.h>
void check(int *score, int n, int *mb, int *lb)
{
    *mb = *lb = 0;
    int hst, lst;
    hst = lst = *score;
    for (int i = 0; i < n; i++)
    {
        if (*(score + i) > hst)
        {
            (*mb)++;
            hst = *(score+i);
        }
        else if (*(score + i) < lst)
        {
            (*lb)++;
            lst = *(score+ i);
        }
    }
}
int main()
{
    int n, mb, lb;
    scanf("%d", &n);
    int *score = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", score + i);
    }
    check(score,n,&mb,&lb);
    printf("%d %d",mb,lb);
    return 0;
}