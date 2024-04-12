#include <stdio.h>

int main()
{
        char s[100];
        int n=0,count=0;
        scanf("%s",s);
        while(s[n]!='\0')
        {
                if(s[n]=='c')
                {
                        if(s[n+1]=='='||s[n+1]=='-') n+=2;
                        else n++;
                }
                else if(s[n]=='d')
                {
                        if(s[n+1]=='-') n+=2;
                        else if(s[n+1]!='\0')
                        {
                                if(s[n+1]=='z'&&s[n+2]=='=') n+=3;
                                else n++;
                        }
                        else n++;
                }
                else if(s[n]=='l'&&s[n+1]=='j') n+=2;
                else if(s[n]=='n'&&s[n+1]=='j') n+=2;
                else if(s[n]=='s'&&s[n+1]=='=') n+=2;
                else if(s[n]=='z'&&s[n+1]=='=') n+=2;
                else n++;
                count++;
        }
        printf("%d",count);
}