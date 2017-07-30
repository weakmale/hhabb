#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
typedef long long LL;
int main(){
	int T ,t=1; scanf("%d",&T);
	while(T--){
        LL x; LL a;
        scanf("%lld",&x);
        for(LL i=1;i<=x;i++){
            LL w=i*i;
            if(w>=x){
                a=i;break;
            }
        }
        LL m=a*a-x+1;
        
        if(a%2==0){
	//		printf("%lld %lld\n",a,m);
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
