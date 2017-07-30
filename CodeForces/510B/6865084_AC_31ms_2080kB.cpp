#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
char map[55][55];
bool vis[55][55];
int n,m;
int xi[4]={1,-1,0,0};
int yi[4]={0,0,1,-1};
int step;
int xe,ye;
bool K;
void DFS(int x,int y){
    vis[x][y]=true;
    if(step>=4){
        for(int i=0;i<4;i++){
            int nx=x+xi[i];
            int ny=y+yi[i];
//            printf("~~~~%d~~%d~~~%d\n",x,y,step);
            if(nx==xe&&ny==ye){
                K=true;
            }
        }
    }
    if(K)
        return ;
    for(int i=0;i<4;i++){
        int nx=x+xi[i];
        int ny=y+yi[i];
        if(!vis[nx][ny]&&nx>=0&&ny>=0&&nx<n&&ny<m&&map[nx][ny]==map[xe][ye]){
            step++;
            DFS(nx,ny);
            step--;
        }
    }
    vis[x][y]=false;
}
int main(){
	scanf("%d %d",&n,&m);K=false;
	memset(vis,false,sizeof(vis));
	for(int i=0;i<n;i++)
        scanf("%s",map[i]);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            step=1;xe=i;ye=j;
            DFS(i,j);
            if(K){
                printf("Yes\n");
                return 0;
            }
        }
    }
	printf("No\n");
	return 0;
}