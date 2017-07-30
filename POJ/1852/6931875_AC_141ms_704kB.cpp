#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
const int MAXN=1e6+10;
int a;
int main(){
	int T;  scanf("%d", &T);
	while(T--){
        int L,n; scanf("%d %d",&L,&n);
        int maxx=0; int minn=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a);
            minn=max(minn,min(a,L-a));
            maxx=max(maxx,max(a,L-a));
        }
        printf("%d %d\n",minn,maxx);

	}

	return 0;
}
