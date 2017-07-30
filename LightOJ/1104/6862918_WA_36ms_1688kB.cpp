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
        double t=n-1;int i=1;
        double x=1;
        while(true){
            x*=(t/n);
            if(1.0-x>=0.5)
                break;
            i++; t--;
        }
        if(n==1)
            i=0;
        printf("Case %d: %d\n",m++,i);
	}
	return 0;
}