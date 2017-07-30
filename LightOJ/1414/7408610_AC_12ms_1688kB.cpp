#include "cstdio"
#include "iostream"
using namespace std;
typedef long long LL;
bool judge(LL year){ return year%(year%100?4:400)?0:1; }
int main(){
    int T; scanf("%d",&T); int kcase=1;
    string st1="January";
    string st2="February";
    while(T--){
        string s1; int day1; LL year1;
        cin>>s1; scanf("%d,%lld",&day1,&year1);
        string s2; int day2; LL year2;
        cin>>s2; scanf("%d,%lld",&day2,&year2);
        LL ans=(year2/4-year2/100+year2/400)-(year1/4-year1/100+year1/400);
//        printf("%lld %d\n",ans,day2);
        if(judge(year1) && ( (s1==st1) || ( (s1==st2) && day1<=29 ) )) ans++;
        if(judge(year2) && ( (s2==st1) || ( (s2==st2) && day2< 29 ) )) ans--;
        printf("Case %d: %lld\n",kcase++,ans);
    }
    return 0;
}