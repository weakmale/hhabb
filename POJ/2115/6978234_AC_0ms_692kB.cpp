#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
typedef long long LL;
LL bk[40];
LL x,y;
void init(){
    bk[0]=1;
    for(int i=1;i<=35;i++)
        bk[i]=bk[i-1]<<1;
}
LL EXGCD(LL a,LL b){
    if(b==0){
        x=1; y=0; return a;
    }
    LL r=EXGCD(b,a%b);
    LL t=x;
    x=y;
    y=t-a/b*x;
    return r;
}
int main(){
	LL A,B,C,K;
	init();
	while(scanf("%lld %lld %lld %lld",&A,&B,&C,&K),A||B||C||K){
        LL a=C; LL b=bk[K]; LL c=B-A;
        LL d=EXGCD(a,b);
        if(c%d)
            printf("FOREVER\n");
        else{
            b/=d; x=x*(c/d); x=(x%b+b)%b;
            printf("%lld\n",x);
        }
	}
	return 0;
}
