#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
int n,m;
char Map[1010][1010];
bool vis[1010][1010];
struct node{
    int x; int y; int step;
};
int xi[4]={1,-1,0,0};
int yi[4]={0,0,1,-1};
int ex,ey;
int BFS(int x,int y){
    memset(vis,false,sizeof(vis));
    vis[x][y]=true; int ans=0;
    node a; a.x=x; a.y=y; a.step=0;
    queue<node> Q; Q.push(a);
    while(!Q.empty()){
        node now=Q.front();  Q.pop();
        if(now.step>ans){
            ex=now.x; ey=now.y;
            ans=now.step;
        }
        for(int i=0;i<4;i++){
            int nx=now.x+xi[i];
            int ny=now.y+yi[i];
            if(!vis[nx][ny]&&nx>=0&&ny>=0&&nx<n&&ny<m&&Map[nx][ny]=='.'){
                node End; End.x=nx; End.y=ny; End.step=now.step+1;
                vis[nx][ny]=true;
                Q.push(End);
            }
        }
    }
    return ans;
}
int main(){
    int T;scanf("%d",&T);
	while(T--){
	    scanf("%d %d",&m,&n);
	    int k=0;

        for(int i=0;i<n;i++){
            scanf("%s",Map[i]);
            for(int j=0;j<m;j++){
                if(Map[i][j]=='.'){
                    ex=i;ey=j;
                }
            }
        }
        BFS(ex,ey);
        int ans=0;
        ans=max(ans,BFS(ex,ey));
        printf("Maximum rope length is %d.\n",ans);
	}
	return 0;
}
