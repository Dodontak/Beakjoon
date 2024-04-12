#include <stdio.h>
int main(void)
{
    int h,m,h1,m1;
    scanf("%d %d",&h,&m);
    if(m-45<0)
    {
        m1=m+15;
        h1=h-1;
        if(h1<0)
        {
            h1=23;
        }
    }
    else
    {
        h1=h;
        m1=m-45;
    }
    printf("%d %d",h1,m1);
    return 0;
}