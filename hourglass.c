#include <stdio.h>
int main()
{
    int arr[6][6], result[4][4], max;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            result[i][j] = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1] + arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2];
            if (i == 0 && j == 0)
            {
                max = result[i][j];
            }
            if (result[i][j] > max)
            {
                max = result[i][j];
            }
        }
    }
    printf("%d", max);
    return 0;
}