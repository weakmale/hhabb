#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
typedef long long LL;
LL x,y;
LL EXGCD(LL a,LL b){
    if(b==0){
        x=1; y=0;
        return a;
    }
    LL r=EXGCD(b,a%b);
    LL t=x;
    x=y;
    y=t-a/b*y;
    return r;
}
int main(){
	LL a; LL b;
	while(scanf("%lld %lld",&a,&b)!=EOF){
        LL d=EXGCD(a,b);
        if(d!=1)
            printf("sorry\n");
        else{
            b/=d; x/=d; x=(x%b+b)%b;b*=d;
            printf("%lld %lld\n",x,(1-a*x)/b);
        }
	}
	return 0;
}
