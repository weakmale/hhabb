#include<cstdio>
#include<queue>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=1000+10;
struct node{
	int x;
	int y;
	int stp;
};
int x,y;
char map[MAXN][MAXN];
int r,c;
int vir[MAXN][MAXN];
bool vis[MAXN][MAXN];
int cnt;
int xi[4]={1,-1,0,0};
int yi[4]={0,0,1,-1};
void BFS(){
	memset(vis,false,sizeof(vis));  memset(vir,0,sizeof(vir));   cnt=0;
	node a;   a.x=x;   a.y=y;   a.stp=0;   vis[x][y]=true;  vir[x][y]=0;  
	queue<node> Q;     Q.push(a);
	while(!Q.empty()){
		node now;  now=Q.front();  Q.pop();
		for(int i=0;i<4;i++){
			node end;
			end.x=now.x+xi[i];
			end.y=now.y+yi[i];
			end.stp=now.stp+1;
			if(!vis[end.x][end.y]&&end.x>=1&&end.x<=r&&end.y>=1&&end.y<=c&&map[end.x][end.y]=='.'){
				if(end.stp>cnt){
					cnt=end.stp;
					x=end.x;
					y=end.y;
				}
				vis[end.x][end.y]=true;
				Q.push(end);
			}
		}
	}
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int k=false;
		scanf("%d %d",&c,&r);
		for(int i=1;i<=r;i++){
			scanf("%s",map[i]);
			if(!k){
				for(int j=1;j<=c;j++){
					if(map[i][j]=='.'){
						x=i;y=j;k=true;
						break;
					}
				}
			}
		}
		BFS();
		BFS();
		printf("Maximum rope length is %d.\n",cnt);
	}
	return 0;
}