#include <stdio.h>
int main(void)
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    b+=c%60;
    if(b>59)
    {
        a++;
        b-=60;
    }
    a+=c/60;
    if(a>23) a-=24;
    printf("%d %d",a,b);
    return 0;
}