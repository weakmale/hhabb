#include<cstdio>
#include<math.h>
int main()
{
    int x,y;
    while(scanf("%d%d",&x,&y)!=EOF)
    {    if(x==0&&y==0)
            break;
        int k=0,n;
        double m;
        for(int i=x;i<=y;i++)
        {
            n=i*i+i+41;
            m=sqrt(n);
            for(int j=2;j<m;j++)
            {
                if(n%j==0)
                {k=1; break;}
            }
        }
        if(k)
            printf("Sorry\n");
        else
            printf("OK\n");
    }
    return 0;
}