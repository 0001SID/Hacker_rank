#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int even_sum(int num,int remain)
{
    return (num + (num - (remain -1)))*(remain/2);
}
int odd_sum(int num, int remain)
{
    return ((num + (num - (remain -1)))*((remain-1)/2)) + (num - (remain-1)/2);
 
}
int main()
{
    int t,remain,sum,rem_sum,sum_status = 0,last_digit;
    scanf("%d",&t);
    int data[t][3];
    for(int i = 0 ; i< t ; i++)
    {
        scanf("%d %d %d",&data[i][0],&data[i][1],&data[i][2]);
    }
    for(int i = 0; i< t; i++)
    {
        remain = data[i][2];
        rem_sum = data[i][0];
        for(int j = 0; j< data[i][2]; j++)
        {
            // printf("remain %d   ",remain);
            if(remain%2 == 0)
            {
                sum = even_sum(data[i][1],remain);
                if(sum >= rem_sum)
                {
                    sum = even_sum(rem_sum,remain);
                    sum_status = 1;
                }
                // printf("even sum = %d ",sum);
            }
            else if( remain %2 != 0)
            {
                sum = odd_sum(data[i][1],remain);
                if(sum  >=rem_sum)
                {
                    sum = odd_sum(rem_sum,remain);
                    sum_status = 1;
                }
                // printf("odd sum = %d  ",sum);
            }
            if(j == 0 && sum < data[i][0])
            {
                printf("-1");
                break;
            }
            if(sum == rem_sum)
            {
                if(sum_status == 1)
                {
                    last_digit = rem_sum;
                }
                else
                {
                    last_digit = data[i][1];
                }
                for(int j = 0 ; j < remain; j++)
                {
                    printf("%d ",last_digit - (remain -1-j));
                }
                last_digit = 0;
                // printf("reach %d ",sum);
                break;
            }
            else 
            {
                printf("%d ",j+1);
                remain--;
                rem_sum -= j+1;
            }
        }
        printf("\n");
    }
    return 0;
}