#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int main(){
	int T; scanf("%d",&T);int m=1;
	while(T--){
        double n;
        scanf("%lf",&n);
        double t=n;
        double x=1;
        int i;
            i=0;
        while(t>0){
            x*=(t/n);//不一样的概率
            if(x<=0.5)
                break;
            i++;
            t--;
        }
        if(n==1)
            i=0;
        printf("Case %d: %d\n",m++,i);
	}
	return 0;
}