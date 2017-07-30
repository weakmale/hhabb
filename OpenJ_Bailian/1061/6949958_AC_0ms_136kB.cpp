#include "cstdio"
int p,q;
int EXGCD(int a,int b){
    if(b==0){
        p=1;
        q=0;
        return a;
    }
    int r=EXGCD(b,a%b);
    int t=p;
    p=q;
    q=t-a/b*q;
    return r;
}
int main(){
    int  x,y,m,n,l;
    while(~scanf("%d %d %d %d %d",&x,&y,&m,&n,&l)){
        int a=n-m;int b=l;int c=x-y;
        int G=EXGCD(a,b);
        if(c%G)
            printf("Impossible\n");
        else{
//            a/=G; b/=G; c/=G;
//            EXGCD(a, b);
            p*=c;
            int t=p%b;
            while(t<0)
                t+=b;
            printf("%d\n",t);
        }
    }
    return 0;
}