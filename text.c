#include <stdio.h>
#include <conio.h>
int main()
{
    FILE *fp;
    char c;
    fp = fopen("file.txt","w");
    fprintf(fp,"This is the content of file");
    fclose(fp);
    fopen("file.txt","r");
    printf("The contents in the file is\n");
    while((c = fgetc(fp)) != EOF)
    {
        printf("%c",c);
    }
    fclose(fp);
    getch();
    return 0;
}