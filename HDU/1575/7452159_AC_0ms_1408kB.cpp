#include "cstdio"
#include "cstring"
const int mod=9973;
int n;
struct Mat{
    int Map[11][11];
    void init(){memset(Map,0, sizeof(Map));  }
};
Mat operator * (Mat a,Mat b){
    Mat c; c.init();
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=0;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++)
                c.Map[i][j]=(c.Map[i][j]+a.Map[i][k]*b.Map[k][j])%mod;
        }
    }
    return c;
}
Mat operator ^ (Mat base,int m){
    Mat ans; ans.init();
    for(int i=1;i<=n;i++) ans.Map[i][i]=1;
    while(m){
        if(m&1) ans=ans*base;
        base=base*base;
        m>>=1;
    }
    return ans;
}
int main(){
    int T; scanf("%d",&T);
    while(T--){
        int k; scanf("%d %d",&n,&k);
        Mat M;
        M.init();
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&M.Map[i][j]);
        M=M^k;
        int sum=0;
        for(int i=1;i<=n;i++) sum=(sum+M.Map[i][i])%mod;
        printf("%d\n",sum);
    }
    return 0;
}