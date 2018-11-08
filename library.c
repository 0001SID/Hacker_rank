#include<stdio.h>
#include<string.h>
int main()
{
    int total_number_of_books[100] = {0};  //total number of books in each selves
    int total_number_of_shelves; 
    int total_number_of_pages[100][100] = {0}; // Number of pages in each selves on each book number

    scanf("%d", &total_number_of_shelves);
    
    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);
    
    while (total_number_of_queries--) 
    {
        int type_of_query;
        scanf("%d", &type_of_query);
        
        if (type_of_query == 1) 
        {
            int x, y;
            scanf("%d %d", &x, &y);
            total_number_of_books[x] += 1;
            total_number_of_pages[x][total_number_of_books[x]-1] = y;
        } 
        else if (type_of_query == 2) 
        {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", total_number_of_pages[x][y]);
        }
        else 
        {
            int x;
            scanf("%d", &x);
            printf("%d\n",total_number_of_books[x]);
        }
    }

    return 0;
}