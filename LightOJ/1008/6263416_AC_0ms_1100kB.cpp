#include<cstdio>
#include<cmath>
int main()
{
    long long s,n,m,x,y,k=1,t;
    double a,b;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lf",&a); b=sqrt(a);n=b;s=a;
        printf("Case %lld: ",k++);
        if(n*n==s)
        {
            if(n%2==0) {printf("%lld 1\n",n);continue;}
            else {printf("1 %lld\n",n); continue;}
        }
        n++;
        if(n*n-s<n)
        {
            x=n; y=n*n+1-s;
        }
        else {y=n;x=2*n-n*n-1+s;}
        if(n%2!=0){m=y;y=x;x=m;}
        printf("%lld %lld\n",x,y);
    }
    return 0;
}