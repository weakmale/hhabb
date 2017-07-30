#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
const int MAXX=40000+10;
const int INF=0x3f3f3f3f;
int a[MAXX];
int n;
int c[MAXX];
int ans;
int main(){
	int T; scanf("%d",&T);
	while( T-- ){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),c[i]=INF;
        ans=0;
        for(int i=1;i<=n;i++)
        {
            int k=lower_bound(c+1,c+1+n,a[i])-c;
            c[k]=min(c[k],a[i]);
            ans=max(ans,k);
        }
        printf("%d\n",ans);
	}

	return 0;
}
