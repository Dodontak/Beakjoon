#include <stdio.h>

int main(void)
{
        int t;
        char s[20];
        scanf("%d",&t);
        for(int i=0;i<t;i++)
        {
                int k,n=0;
                scanf("%d %s",&k,s);
                while(s[n]!='\0')
                {
                        for(int j=0;j<k;j++)
                        {
                                printf("%c",s[n]);
                        }
                        n++;
                }
                printf("\n");
        }
}
