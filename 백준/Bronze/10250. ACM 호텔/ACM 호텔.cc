#include <stdio.h>

int main()
{
        int t;
        scanf("%d",&t);
        for(int i=0;i<t;i++)
        {
                int h,w,n,x,y;
                scanf("%d %d %d",&h,&w,&n);
                x=n%h;//층
                if(x==0)
                {
                        x=h;
                        y=n/h;
                }
                else
                        y=n/h+1;//호

                if(y<10) printf("%d0%d\n",x,y);
                else printf("%d%d\n",x,y);
        }

        return 0;
}