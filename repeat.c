#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char s[100];
    scanf("%s", &s);
    long int n, count = 0;
    scanf("%ld", &n);
    char * temp = malloc(strlen(s) * sizeof(char));
    for (int i = 0; i < strlen(s); i++)
    {
        temp[i] = 'a';
    }
    if (strcmp(temp, s) == 0)
    {
        count = n;
    }
    else
    {
        for (long int i = 0; i < n;)
        {
            for (long int j = 0; j < strlen(s); i++, j++)
            {
                if (i == n)
                    break;
                if (s[j] == 'a')
                    count++;
            }
        }
    }
    printf("%ld", count);
    return 0;
}