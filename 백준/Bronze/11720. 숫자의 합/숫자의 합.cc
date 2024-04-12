#include <stdio.h>

int main()
{
        int n,sum=0;
        scanf("%d",&n);
        char s[n];
        scanf("%s",s);
        for(int i=0;i<n;i++)
        {
                sum+=s[i]-'0';
        }
        printf("%d",sum);
        return 0;       
}