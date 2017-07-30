#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
int n;
int m;
int a[10010];
int k[10010];
int main(){
    int t=1;
	while(scanf("%d %d",&n,&m)!=EOF){

        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        printf("Case %d:\n",t++);
        memset(k,0,sizeof(k));
        int minn=10000000; int maxx=0;
        for(int i=1;i<=n;i++){
            minn=a[i]; maxx=a[i];
            for(int j=i;j<=n;j++){
                maxx=max(maxx,a[j]);
                minn=min(minn,a[j]);
                int K=maxx-minn;
                if(K==j-i){
                    k[K+1]++;
                }
            }
        }
        int K;
        for(int i=1;i<=m;i++){
            scanf("%d",&K);
            printf("%d\n",k[K]);
        }
	}
	return 0;
}
