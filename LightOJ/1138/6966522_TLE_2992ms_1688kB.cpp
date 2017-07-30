#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
typedef long long LL;
LL maxx[100]={1};
int main(){
	int T,t=1;scanf("%d",&T);
	while(T--){
		LL Q,q; scanf("%lld",&Q); LL i=5; 
		while(Q>0){
			LL k=i; LL j=0; q=Q;
			while(k%5==0)
				k/=5,j++;
			Q-=j;
			if(Q<=0)
				break;
			i+=5;
		}
		if(Q<0)
		printf("Case %d: impossible\n",t++);
		else
		printf("Case %d: %lld\n",t++,i);
	}
	return 0;
}
