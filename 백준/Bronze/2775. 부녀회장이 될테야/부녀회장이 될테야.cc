#include <stdio.h>

int main()
{
        int t,k,n,arr[15][15]={0};
        scanf("%d",&t);
        for(int i=0;i<15;i++)
        {
                arr[0][i]=i+1;
        }
        for(int i=1;i<15;i++)
        {
                for(int j=0;j<15;j++)
                {
                        for(int l=0;l<=j;l++)
                        {
                                arr[i][j]+=arr[i-1][l];
                        }
                }
        }
        while(t--)
        {
                scanf("%d %d",&k,&n);
                printf("%d\n",arr[k][n-1]);
        }
        return 0;
}