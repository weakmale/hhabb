#include "cstdio"
int x,y,m,n,l;
int p,q,c;
int GCD(int a,int b){
    if(b==0)
        return a;
    return GCD(b,a%b);
}
void EXGCD(int a,int b){
    if(b==0){
        p=1;
        q=0;
        return ;
    }
    else{
        EXGCD(b, a%b);
        int t=p;
        p=q;
        q=t - a / b * q;
    }
}
int main(){
    while(scanf("%d %d %d %d %d",&x,&y,&m,&n,&l)!=EOF)
    {
        int d=x-y; int b=l; int a=n-m;
        int G=GCD(a, b);
        if(d % G){
            printf("Impossible\n");continue;
        }
        else{
            a/=G; b/=G; d/=G;
            EXGCD(a, b);  p*=d;
            p%=b;
            while(p<0)
                p+=b;
            printf("%d\n",p);
        }
    }
}