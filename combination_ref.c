#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    int n,r, count = 0,check=1;
    printf("Enter the length of the numbr\n");
    scanf("%d", &n);
    printf("Enter the range\n");
    scanf("%d",&r);
    int *arr = malloc(n * sizeof(int));
    int *temp = malloc(r * sizeof(int));
    int *pos = malloc(r * sizeof(int));
    int *rept = malloc(r * sizeof(int));
    memset(pos, 0, r*sizeof(int));
    memset(rept, 0, r*sizeof(int));
    printf("Enter the elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",arr+i);
    }
    while (check <= pow(n,r))
    {
        for (int i = 0; i < r; i++) //for making the number of array
        {
            temp[i] = arr[pos[i]];
        }
        for (int i = 0; i < r; i++) //for printing the array
        {
            printf("%d", temp[i]);
        }
        printf("\n");
        for (int i = 0; i < r; i++)
        {
            if (pos[i] == n - 1)
            {
                rept[i]++; //To check how much time the number is repeated in a coloumn
            }
            if ((pos[i] == n - 1) && (rept[i] == pow(n, r-i-1))) //If it is repeated a specific number of time then chnage the value of it's previous position
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
        // for (int i = 0; i < n; i++) //we can also use this formula to terminate the loop
        // {
        //     if ((pos[i] == n - 1))
        //     {
        //         count++; //To check if it is the last number of combination or not
        //     }
        // }
        // if (count == n)
        //     break;
        //     count =  0;
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
    // free(pos); //Does not know why this is not showing "double free or corruption (out)" but working in windows.
    // free(rept);
    // free(temp);
    // free(arr);
    // realloc(pos,0);
    // realloc(rept,0);
    // realloc(temp,0);
    // realloc(arr,0);
    return 0;
} 