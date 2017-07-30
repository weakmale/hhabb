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
int vis[100010];
int main(){
	while(scanf("%d %d",&n,&m)!=EOF){

        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        printf("Case #1:\n");
        memset(k,0,sizeof(k));
        int minn=0; int maxx=0;
        for(int i=1;i<=n;i++){
            memset(vis,0,sizeof(vis));
            minn=a[i]; maxx=a[i];
            for(int j=i;j<=n;j++){
                maxx=max(maxx,a[j]);
                minn=min(minn,a[j]);
                int K=maxx-minn+1;
                if(!vis[a[j]]){
                    if(K==j-i+1)
                        k[K]++;
                    vis[a[j]]=1;
                }
                else
                    break;
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
