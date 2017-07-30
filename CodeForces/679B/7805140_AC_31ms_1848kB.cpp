#include "cstdio"
#include "algorithm"
using namespace std;
typedef long long LL;
LL maxxs;
LL maxxt;
LL pow(LL x){return  x*x*x;}
LL pp(LL n){
    LL x=0;
    while(pow(x)<=n) x++;
    return x-1;
}
void DFS(LL n,LL time,LL cnt){
//    printf("%lld %lld %lld %lld %lld\n",n,time,cnt,maxxt,maxxs);
    if(n<=7){
        time+=n;
        cnt+=n;
        if(maxxt<time){
            maxxt=time; maxxs=cnt;
        }
        else if(maxxt==time) maxxs=max(maxxs,cnt);
        return ;
    }
    LL x=pp(n);
    DFS(n-pow(x),time+1,cnt+pow(x));
    DFS(pow(x)-pow(x-1)-1,time+1,cnt+pow(x-1));
}
int main(){
    LL n; scanf("%lld",&n);
    maxxt=0;maxxs=0;
    DFS(n, 0, 0);
    printf("%lld %lld\n",maxxt,maxxs);
}