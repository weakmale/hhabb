#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
typedef long long LL;
int main(){
	int T; scanf("%d",&T); int t=1;
	while(T--){
        LL a,b;
        scanf("%lld %lld",&a,&b);
        LL sum=(a-1)*a/2;
        LL te=0;
        for(LL i=a;i<=b;i++){
            sum+=i;
            if(sum%3==0)
                te++;
        }
        printf("Case %d: %lld\n",t++,te);
	}
	return 0;
}
