#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void comb(long int *arr, long int n, long int r, long int stick)
{
    long int check = 1, sum = 0;
    int poscheck = 0, status = 0;
    long int *temp = malloc(r * sizeof(long int));
    long int *pos = malloc(r * sizeof(long int));
    long int *rept = malloc(r * sizeof(long int));
    memset(pos, 0, r * sizeof(long int));
    memset(rept, 0, r * sizeof(long int));
    while (check <= pow(n, r))
    {
        if (n == 20)
        printf("%ld  ",check);
        for (long int i = 0; i < r; i++) //for making the number of array
        {
            for (long int j = 0; j < r; j++) //For checking that no number is repeating.
            {
                if (i == j)
                    continue; //for skip checking of the same elemnt
                else if (pos[i] == pos[j])
                {
                    poscheck = 1;
                    break;
                }
            }
            if (poscheck == 1)
                break;
            temp[i] = arr[pos[i]];
            sum += temp[i];
        }
        if ((sum == stick) && poscheck == 0)
        {
            for (long int i = 0; i < r; i++)
            {
                printf("%ld ", temp[i]);
            }
            status = 1;
            printf("\n");
            break;
        }
        sum = 0, poscheck = 0;
        for (long int i = 0; i < r; i++)
        {
            if (pos[i] == n - 1)
            {
                rept[i]++; //To check how much time the number is repeated in a coloumn
            }
            if ((pos[i] == n - 1) && (rept[i] == pow(n, r - i - 1))) //If it is repeated a specific number of time then chnage the value of it's previous position
            {
                if (check != pow(n, r))
                {
                    if (pos[i - 1] == n - 1) //if the previous number is the last number then it will start the series again
                    {
                        pos[i - 1] = 0;
                    }
                    else
                        pos[i - 1]++; //If the previous number is not the last number of series then go to the next number
                }
                rept[i] = 0;
            }
        }
        if (pos[r - 1] < n - 1) //for go to the next number of series in the last line
        {
            pos[r - 1]++;
        }
        else
        {
            pos[r - 1] = 0; //if it is the last number of series then start form the first again
        }
        check++;
    }
    if (status == 0)
    {
        printf("-1\n");
    }
    free(pos); //Does not know why this is showing "double free or corruption (out)" in linux but working in windows.
    free(rept);
    free(temp);
}
int main()
{
    long int n, data[3], j = 0;
    scanf("%ld", &n);
    long int *arr;
    while (j < n)
    {
        for (long int i = 0; i < 3; i++)
        {
            scanf("%ld", &data[i]);
        }
        arr = (long int *)malloc(data[1] * sizeof(long int));
        for (long int i = 0; i < data[1]; i++)
        {
            arr[i] = i + 1;
        }
        comb(arr, data[1], data[2], data[0]);
        j++;
    }
    free(arr);
    return 0;
}