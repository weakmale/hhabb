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
LL cnt[1050];
LL f[1050][1050];
/*bool cmp(int a,int b)
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
    init();
	while(~scanf("%d",&n)){
	    LL cnt1;
        memset(cnt,0,sizeof(cnt));
        memset(ans,0,sizeof(ans));
        for(int i=1;i<=n;i++){
            scanf("%lld",&num[i]);
//            ans[1]+=num[i];
//            if(i==1)
 //               ans[n]=num[i];
 //           else
      //          ans[n]^=num[i];
     }
        LL ml=1; int k=1;
       /* while(num[1]){
            for(int i=1;i<=n;i++){
                if(!num[i])
                    break;
                if(num[i]&1)
                    cnt[k]++;
//                cout<<num[i]<<"~~~"<<i<<endl;
                num[i]>>=1;
            }
            k++;
        }*/
        for(int i=1;i<=n;i++)
        {
            LL t=num[i];
            k=1;
            while(t)
            {
                if(t&1)
                    cnt[k]++;
                k++;
                t>>=1;
            }
        }
        for(int i=1;i<=n;i++){
            LL sum=0;ml=1;
            for(int l=1;l<=32;l++){
                cnt1=0;
                for(int j=1;j<=cnt[l]&&j<=i;j+=2){
//                    LL a=C(j,cnt1);
//                    LL b=C(i-j,cnt2);
                    cnt1=(cnt1+f[cnt[l]][j]*f[n-cnt[l]][i-j]%mod)%mod;
                }
                cnt1*=ml%mod;
                sum+=cnt1;
                ml*=2;
//                    cout<<C(j,cnt1)<<"----"<<j<<"~~~~"<<i<<"~~~~~~"<<C(i-j,cnt2)<<"____"<<ml<<")))))"<<cnt1<<">>>>:"<<ans[i]<<endl;
            }
            ans[i]=sum;
        }
        for(int i=1;i<n;i++)
            printf("%lld ",ans[i]);
        printf("%lld\n",ans[n]);
	}
	return 0;
}