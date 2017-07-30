#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
typedef long long LL;
int main(){
	int T ,t=1; scanf("%d",&T);
	while(T--){
        LL x; LL a;
        scanf("%lld",&x);
        double y=sqrt(x);
        if( LL(y*1000000)%1000000==0)
        	a=LL(y);
        else
        	a=LL(y)+1;
        LL m=a*a-x+1;
        
        if(a%2==0){
        	if(m>a)
            	printf("Case %d: %lld %lld\n",t++,a+a-m,a);
        	else
            	printf("Case %d: %lld %lld\n",t++,a,m);
            }
        else
        	if(m>a)
        		printf("Case %d: %lld %lld\n",t++,a,a+a-m);
        	else
        		printf("Case %d: %lld %lld\n",t++,m,a);
	}

	return 0;
}
