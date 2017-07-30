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
LL num[1050];
LL ans[1050];
LL f[1050][1050];
bool cmp(int a,int b)
{
    return a>b;
}
/*LL Qpow(LL  n,LL m){
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
    return f[b]*Qpow(f[a]*f[b-a]%mod,mod-2)%mod;
}*/
void init()
{
    memset(f,0,sizeof(f));
    for(int i=0;i<1050;i++)
        f[i][0]=f[i][i]=1;
    for(int i=1;i<1050;i++)
        for(int j=1;j<i;j++)
            f[i][j] = (f[i-1][j]+f[i-1][j-1])%mod;
}
int main(){
//    fac[0]=1;
 //   for(int i=1;i<1010;i++)
 //       fac[i]=fac[i-1]*i%mod;
    init();
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
            for(int i=2;i<n;i++){
                for(int j=1;j<=cnt1&&j<=i;j+=2){
//                    LL a=C(j,cnt1);
//                    LL b=C(i-j,cnt2);
                      ans[i]+=f[cnt1][j]*f[cnt2][i-j]*ml%mod;
//                    cout<<C(j,cnt1)<<"----"<<j<<"~~~~"<<i<<"~~~~~~"<<C(i-j,cnt2)<<"____"<<ml<<")))))"<<cnt1<<">>>>:"<<ans[i]<<endl;
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
