#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
const int MAXN=1e6+10;
int a[MAXN];
int main(){
	int T;  scanf("%d", &T);
	while(T--){
        int L,n; scanf("%d %d",&L,&n);  int minn=0; int minnn=0; int maxx=0; int maxxx;
        for(int i = 1; i <= n; i++){
            scanf("%d",&a[i]);
            minn=min( a[i], abs( L - a[i] ) );
            minnn=max(minn,minnn);
            maxx=max( a[i], abs(L-a[i]));
            maxxx=max(maxxx,maxx);
        }
        printf("%d %d\n",minnn,maxxx);

	}

	return 0;
}
