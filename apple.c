#include<stdio.h>
void inp(int *p,int n)
{
    for(int i = 0; i<n; i++)
    {
        scanf("%d",p+i);
    }
}
int count(int pos,int *dis,int *range,int n)
{
    int count=0;
    for(int i = 0; i< n ; i++)
    {
        if((pos + *(dis+i) >= *range) && (pos + *(dis+i)<= *(range+1)))
        {
            count++;
        }
    }
    return count;
}
int main()
{
    int home[2],tree[2],ao[2],ac,oc;
    inp(home,2);inp(tree,2);inp(ao,2);
    int apple[ao[0]],orange[ao[1]];
    inp(apple,ao[0]);inp(orange,ao[1]);
    ac = count(tree[0],apple,home,ao[0]);
    oc = count(tree[1],orange,home,ao[1]);
    printf("%d\n%d",ac,oc);
    getch();
    return 0;
}