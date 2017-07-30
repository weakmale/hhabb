#include "cstdio"
long long  GCD( long long  x, long long  y )
{
    if( y== 0 )
    {
        return x;
    }
    return GCD( y, x% y );
}
void EXGCD( long long  a, long long  b, long long  &x, long long  &y )
{
    if( b== 0 )
    {
        x= 1;
        y= 0;
        return;
    }
    EXGCD( b, a% b, x, y );
    long long  t= x;
    x= y;
    y= t- a/ b* y;
    return;
}
int main(){
    
    long long int x, y, m, n, l;
    while( scanf( "%lld %lld %lld %lld %lld", &x, &y, &m, &n, &l )!= EOF )
    {
        long long  a= n- m, b= l, c= x- y;
        long long  G= GCD( a, b );
        if(c%G){
            printf("Impossible\n");
            continue;
        }
        a/=G; b/=G; c/=G;
        long long p,q;
        EXGCD(a,b,p,q);
        p*= c;
        long long  t= p/G;
        if(t<0)
            t+=b;
        printf("%lld\n",t);
    }
    return 0;
}