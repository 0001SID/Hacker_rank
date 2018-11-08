#include <stdio.h>
#include<stdlib.h>
long int maxi(long int *p, long int n)  //function to determine the position of maximum difference.
{
    int max = *p;
    static int j;
    j = 0;
    for (int i = 0; i < n; i++)
    {
        if (*(p + i) > max)
        {
            max = *p;
            j = i;
        }
    }
    return j;
}
int main()
{
    long int n, min, max, temp, dif_check =0, d,count=0;
    scanf("%ld", &n);
    long int num[n], serial[n], dif[n];
    for (long int i = 0; i < n; i++)
    {
        scanf("%ld", &num[i]);
        printf("i = %ld num = %ld",i,num[i]);
    }
    min = num[0];
    max = num[0];
    for (long int i = 0; i < n; i++)
    {
        if (num[i] < min)
        {
            min = num[i];
        }
        if (num[i] > max)
        {
            max = num[i];
        }
    }
    serial[0] = min;
    for (long int i = 1; i < n; i++) //loop to sort the given array
    {
        serial[i] = max;

        for (int j = 0; j < n; j++)
        {
            if ((num[j] > serial[i - 1]) && (num[j] < serial[i]))
            {
                serial[i] = num[j];
            }
        }
    }
    while(1)
    {
        for (long int i = 0; i < n; i++)
        {
            dif[i] = num[i] - serial[i]; //making the array of the diffence of the given array and the sorted array's value
            dif_check += abs(dif[i]); //sum of the all difference
        }
        if (dif_check == 0) //If all the difference is zero that means the arranged array and the sorted array is in the same serial
        {
            break;
        }
        else
        {
            d = maxi(dif, n);//find the position of the maximum difference
            temp = num[d];
            num[d] = num[d + dif[d]];
            num[d + dif[d]] = temp;//swap the number which have the maximum difference to make the difference zero
            count++; // count the number of step.
            dif_check =0; //make the sum of the difference zero again.
        }
    }
    printf("%ld",count);
    return 0;
}