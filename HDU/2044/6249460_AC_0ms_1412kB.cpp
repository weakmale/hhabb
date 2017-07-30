#include<cstdio>
int main()
{
    int m; scanf("%d",&m);
    while(m--)
    {
        int a,b,n;
        scanf("%d%d",&a,&b);
        n=b-a;
        long long s[n+1];s[1]=1;s[2]=2;
        for(int i=3;i<=n;i++)
            s[i]=s[i-1]+s[i-2];
        printf("%lld\n",s[n]);
    }
    return 0;
}