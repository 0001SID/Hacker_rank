#include <stdio.h>
#include <math.h>
int sign(int x)
{
    int res;
    if (x < 0)
        res = 0;
    else if (x > 0)
        res = 1;
    return res;
}
int main()
{
    int xv[4], x, v;
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &xv[i]);
    }
    x = xv[0] - xv[2];
    v = xv[1] - xv[3];
    if ((sign(x) != sign(v)) &&(x != 0 || v != 0)&& (x % v == 0 || v % x == 0))
    {
        printf("YES");
    }
    else
        printf("NO");
    return 0;
}