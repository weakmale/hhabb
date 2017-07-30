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
LL num[1111];
//LL ans[1111];
LL cnt[1111];
LL f[1111][1111];
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
    for(int i=0;i<1111;i++)
        f[i][0]=f[i][i]=1;
    for(int i=1;i<1111;i++)
        for(int j=1;j<i;j++)
            f[i][j] = (f[i-1][j]+f[i-1][j-1])%mod;
}
int main(){
    init();
	while(~scanf("%d",&n)){
	    LL cnt1;
        memset(cnt,0,sizeof(cnt));
 //       memset(ans,0,sizeof(ans));
        for(int i=1;i<=n;i++){
            scanf("%lld",&num[i]);
//            ans[1]+=num[i];
//            if(i==1)
 //               ans[n]=num[i];
 //           else
      //          ans[n]^=num[i];
     }
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
            int k=1;
            while(t)
            {
                if(t&1)
                    cnt[k]++;
                k++;
                t>>=1;
            }
        }
       for(int k=1;k<=n;k++)
        {
            LL sum = 0;
            LL t = 1;
            for(int i=1;i<32;i++)
            {
                LL ans=0;
                for(int j=1;j<=k;j+=2)
                    ans=(ans+(f[cnt[i]][j]*f[n-cnt[i]][k-j])%mod)%mod;
                sum=(sum+ans*t%mod)%mod;
                t*=2;
            }
            if(k!=1)printf(" ");
            printf("%lld",sum);
        }
        printf("\n");
	}
	return 0;
}
