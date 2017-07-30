#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
typedef long long LL;
const int mod=1000003;
int n;
LL num[1010];
LL ans[1010];
LL fac[1010];
bool cmp(int a,int b)
{
    return a>b;
}
LL Qpow(LL  n,LL m){
    LL ans=1; LL base=n;
    while(m){
        if(m&1)
            ans=(ans*base)%mod;
        base=(base*base)%mod;
        m>>=1;
    }
    return ans;
}
LL C(LL a,LL b)
{
    return fac[b]*Qpow(fac[a]*fac[b-a]%mod,mod-2)%mod;
}
int main(){
    fac[0]=1;
    for(int i=1;i<1010;i++)
        fac[i]=fac[i-1]*i%mod;
	while(~scanf("%d",&n)){
        memset(ans,0,sizeof(ans));
        for(int i=1;i<=n;i++){
            scanf("%lld",&num[i]);
            ans[1]+=num[i];
            if(i==1)
                ans[n]=num[i];
            else
                ans[n]^=num[i];
        }
        sort(num+1,num+n+1,cmp);
        LL ml=1;
        while(num[1]){
            LL cnt1=0,cnt2=n;
            for(int i=1;i<=n;i++){
                if(!num[i])
                    break;
                if(num[i]&1)
                    cnt1++;
//                cout<<num[i]<<"~~~"<<i<<endl;
                num[i]>>=1;
            }
            cnt2-=cnt1;
            if(cnt1==0||cnt2==0){
                ml<<=1;
                continue;
             }
            for(int i=2;i<n;i++){
                for(int j=1;j<i;j++){
                    LL a=C(j,cnt1);
                    LL b=C(i-j,cnt2);
                    if( j&1 )
                        ans[i]+=a*b*ml%mod;
  //                      cout<<C(j,cnt1)<<"----"<<j<<"~~~~"<<i<<"~~~~~~"<<C(i-j,cnt2)<<"____"<<ml<<")))))"<<cnt1<<">>>>:"<<ans[i]<<endl;
                }
            }
            ml<<=1;
        }
        for(int i=1;i<n;i++)
            printf("%lld ",ans[i]);
        printf("%lld\n",ans[n]);
	}
	return 0;
}
