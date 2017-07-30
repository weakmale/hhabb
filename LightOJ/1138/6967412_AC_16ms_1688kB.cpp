#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
typedef long long LL;
LL Q;
LL  judge(LL mid){
	LL sum=0;
	while(mid){
		sum+=mid/5;
		mid/=5;
	}
	return sum;
}
int main(){
	int T,t=1;
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&Q);
		LL l=0; LL r=1000000000; LL ans=0;
		while(r>=l){
			LL mid=(l+r)>>1;
			if(judge(mid)<Q){
				 l=mid+1;
			}
			else{
				ans=mid;
				r=mid-1;
			}
		}
		
		if(judge(ans)!=Q)
		printf("Case %d: impossible\n",t++);
		else
		printf("Case %d: %lld\n",t++,ans);
	}
	return 0;
}
