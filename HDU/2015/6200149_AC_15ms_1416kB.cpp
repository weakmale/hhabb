
#include<cstdio>
int main()
{
    int  m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        int ave,t,j,s,x;
        ave=n+1;t=m/n,j=0;s=m%n;
        for(int i=0;i<t;i++)
        {
            if(j)
                printf(" ");
            printf("%d",ave);
            j=1;
            ave=ave+2*n;
        }
        if(s!=0)
        {
            x=n*t+1;
            ave=x+x+s-1;
            printf(" %d",ave);
        }
        printf("\n");
    }
    return 0;
}