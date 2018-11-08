#include<stdio.h>
#include<string.h>
int main()
{
    int total_number_of_books[100] = {0};  //total number of books in each selves
    int total_number_of_shelves; 
    int total_number_of_pages[100][100] = {0}; // Number of pages in each selves on each book number
    int *ptr_books = total_number_of_books;
    int *ptr_pages = total_number_of_pages;
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
            *(ptr_books + x) += 1;
            *(ptr_pages + x * 100 + *(ptr_books + x)-1) = y;
        } 
        else if (type_of_query == 2) 
        {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(ptr_pages + x * 100 + y));
        }
        else 
        {
            int x;
            scanf("%d", &x);
            printf("%d\n",*(ptr_books +x));
        }
    }

    return 0;
}