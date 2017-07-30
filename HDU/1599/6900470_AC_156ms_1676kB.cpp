#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
int n;int m;
const int inf=0x3f3f3f;
int mapp[110][110];
int dis[110][110];
int ans;
void init(){
    for(int i=1;i<=100;i++)
        for(int j=1;j<=100;j++)
            if(i-j)mapp[i][j]=inf;
                else mapp[i][j]=0;
}
void Floyd(){
    ans=inf;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j]=mapp[i][j];
   for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    if(i!=j&&i!=k&&j!=k)
                        ans=min(ans,dis[i][j]+mapp[j][k]+mapp[k][i]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);

    }
    if(ans==inf)printf("It's impossible.\n");
    else printf("%d\n",ans);
}
int main(){
    int a,b,c;
    while(~scanf("%d%d",&n,&m)){
        init();
        while(m--){
            scanf("%d%d%d",&a,&b,&c);
            if(c<mapp[a][b])mapp[a][b]=mapp[b][a]=c;
        }
        Floyd();
    }
    return 0;
}
