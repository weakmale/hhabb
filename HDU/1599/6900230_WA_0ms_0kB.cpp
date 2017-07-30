#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
int n;int m;
const int inf=0x3f3f3f3f;
int mapp[110][110];
int dis[110][110];
int ans;
void init(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            mapp[i][j]=inf;
            if(i==j)
                mapp[i][j]=0;
        }
    }
}
void Floyd(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j]=mapp[i][j];
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i!=j&&i!=k&&j!=k)
                    ans=min(ans,mapp[i][j]+dis[i][k]+dis[k][j]);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                mapp[i][j]=min(mapp[i][j],mapp[i][k]+mapp[k][j]);
        }

    }
    if(ans==inf)
        printf("It's impossible.\n");
    else
        printf("%d\n",ans);
}
int main(){
	while(scanf("%d %d",&n,&m)!=EOF){
        init();int a,b,c;
        for(int i=1;i<=m;i++){
            scanf("%d %d %d",&a,&b,&c);
            if(mapp[a][b]>c)
                mapp[a][b]=mapp[b][a]=c;
        }
        ans=inf;
        Floyd();
	}
	return 0;
}
