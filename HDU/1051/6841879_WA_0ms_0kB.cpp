#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
const int MAXX=5000+10;
const int INF=0x3f3f3f;
struct node{
    int L;
    int W;
}ans[MAXX];
int c[MAXX];
int n;
int ant;
bool cmp(node a,node b){
    return a.L<b.L;

}
int main(){
	int T; scanf("%d", &T);
	while( T-- ){
        scanf("%d",&n);
        for(int i = 1; i <= n; ++i ){
            scanf("%d %d",&ans[i].L,&ans[i].W); c[i]=INF;
        }
        sort(ans+1,ans+1+n,cmp); ant=0;
        for(int i=n;i>=1;--i){
            int k=lower_bound(c+1,c+1+n,ans[i].W)-c;
            c[k]=min(c[k],ans[i].W);
            ant=max(k,ant);
        }
        printf("%d\n",ant);
	}
	return 0;
}
