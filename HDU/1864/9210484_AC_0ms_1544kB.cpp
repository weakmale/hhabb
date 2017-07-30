#include "cstdio"
#include "cstring"
#include "algorithm"
using namespace std;
double dp[50];
int main(){
    double many;
    int n;
    while(scanf("%lf %d",&many,&n),n){
        memset(dp, 0, sizeof(dp));
    for(int i=1;i<=n;i++){
        double sum=0;
        double sumA=0,sumB=0,sumC=0;
        char a,c; int K=0;
        
        int k; scanf("%d%c",&k,&c);
        for(int j=1;j<=k;j++){
            double b;
            scanf("%c:%lf%c",&a,&b,&c);
            sum+=b;
            if(b>600){K=1; break; }
            if(a!='A'&&a!='B'&&a!='C'){K=1; break; }
            if(a=='A') sumA+=b;
            if(a=='B') sumB+=b;
            if(a=='C') sumC+=b;
            
        }
        if(sumA+sumB+sumC>1000||sumA>600||sumB>600||sumC>600) continue;
        if(sum>1000||K) continue;
        for(int j=i;j>=1;j--)
            if(dp[j-1]+sum<=many)
                dp[j]=max(dp[j-1]+sum,dp[j]);
    }
    double maxx = 0;
    for(int i=n;i>=0;i--){
            maxx = max(maxx,dp[i]);
    }
    printf("%.2lf\n",maxx);
    }
    return 0;
}
