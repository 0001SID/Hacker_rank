#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long int comb(long int *arr, long int n, long int r, long int m, long int *pair)
{
    int pcheck = 0;
    long int check = 1, sum = 0;
    static long int count;
    count = 0;
    int poscheck = 0, status = 0;
    long int *temp = malloc(r * sizeof(long int));
    long int *pos = malloc(r * sizeof(long int));
    long int *rept = malloc(r * sizeof(long int));
    memset(pos, 0, r * sizeof(long int));
    memset(rept, 0, r * sizeof(long int));
    while (check <= pow(n, r))
    {
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

        for (long int i = 0; i < m; i++)
        {
            for (long int j = 0; j < 2; j++)
            {
                for (long int k = 0; k < r; k++)
                {
                    if (pair[i * 2 + j] == temp[k])
                    {
                        pcheck++;
                        break;
                    }
                }
            }
            if (pcheck == 2)
            {
                pcheck = 1;
                break;
            }
            else
            {
                pcheck = 0;
            }
        }

        if (pcheck == 0)
        {
            count++;
            pcheck = 0;
        }
        else
        {
            pcheck = 0;
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
                if (pos[i - 1] == n - 1) //if the previous number is the last number then it will start the series again
                {
                    pos[i - 1] = 0;
                }
                else
                    pos[i - 1]++; //If the previous number is not the last number of series then go to the next number
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
    free(pos); //Does not know why this is showing "double free or corruption (out)" in linux but working in windows.
    free(rept);
    free(temp);
    return count;
}
int main()
{
    long int n, m;
    static long int count = 0;
    scanf("%ld %ld", &n, &m);
    long int arr[n];
    long int pair[m * 2];
    for (long int i = 0; i < m; i++)
    {
        arr[i] = i + 1;
        for (int j = 0; j < 2; j++)
        {
            scanf("%ld", &pair[i * 2 + j]);
        }
    }
    for (long int i = 0; i < n; i++)
    {
        count += comb(arr, n, i + 1, m, pair);
    }
    printf("%ld", count);
    return 0;
}