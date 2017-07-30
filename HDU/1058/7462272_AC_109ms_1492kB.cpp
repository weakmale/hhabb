#include "cstdio"
#include "map"
#include "algorithm"
using namespace std;
typedef long long LL;
const int Maxx=5842;
LL dp[Maxx+1];
map<LL,bool> Map;
int main(){
    dp[1]=1;
    Map[1]=Map[2]=Map[3]=1;
    int a=1,b=1,c=1,d=1;
    for(int i=2;i<=Maxx;i++){
        LL ans=min( dp[a]*2 , min(dp[b]*3, min(dp[c]*5,dp[d]*7) ) );
        if(ans==dp[a]*2) a++;
        if(ans==dp[b]*3) b++;
        if(ans==dp[c]*5) c++;
        if(ans==dp[d]*7) d++;
        dp[i]=ans;
//        printf("%d %lld\n",i,dp[i]);
    }
    int n;
    while(scanf("%d",&n),n){
        printf("The %d",n);
        if(n % 10 == 1 && n % 100 != 11)
            printf("st");
        else if(n % 10 == 2 && n % 100 != 12)
            printf("nd");
        else if(n % 10 == 3 && n % 100 != 13)
            printf("rd");
        else
            printf("th");
        printf(" humble number is %lld.\n",dp[n]);
    }
    return 0;
}