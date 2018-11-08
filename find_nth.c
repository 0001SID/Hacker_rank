#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.

int find_nth_term(int n, int a, int b, int c) {
  int result,sum;
  if(n<=0)
  {
      if(n == -2)
      result =a;
      else if (n == -1)
      result = b;
      else if (n == 0)
      result = c;
  }
  else
  {
    if( n == 0)
    {
        return c;
    }
    else
    {
        sum = a+b+c;
        n--;
        result = find_nth_term(n,b,c,sum);
    }
  }
  return result;
}

int main() {
    int n, a, b, c;
  
    scanf("%d %d %d %d", &n, &a, &b, &c);
    int ans = find_nth_term(n-3, a, b, c);
 
    printf("%d", ans); 
    return 0;
}