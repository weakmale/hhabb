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
        LL sum=(a+1)*a/2;
        LL x=(b-a+1)/3*2;  
        LL y=(b-a+1)%3;
        for(LL i=1;i<=y;i++){
        	if(sum%3==0)
        		x++;
        	sum+=a+i;
		}
        printf("Case %d: %lld\n",t++,x);
	}
	return 0;
}