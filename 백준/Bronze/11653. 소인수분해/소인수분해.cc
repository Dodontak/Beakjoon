#include <stdio.h>

int main()
{
        int n,i=2;
        scanf("%d",&n);
        while(1)
        {
                if(i>n) break;
                if(n%i==0)
                {
                        printf("%d\n",i);
                        n/=i;
                }
                else i++;
        }     
}