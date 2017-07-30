#include<cstdio>
int main( )
{
    int n;scanf("%d",&n);
    while(n--)
    {
        int t,y=3;scanf("%d",&t);
        for(int i=0;i<t;i++)
            y=(y-1)*2;
        printf("%d\n",y);
    }
    return 0;
}