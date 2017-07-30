#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int n,m;
int MINN;
char map[250][250];
int xy,yy,xm,ym;
int xi[4]={1,-1,0,0};
int yi[4]={0,0,1,-1};
int ds1[250][250];
int ds2[250][250];
struct node{
	int x;
	int y;
	int time;
};
int xp,yp;
bool vis[250][250];
void BFS1(int x,int y){
	node a;
	a.x=x;
	a.y=y;
	a.time=0;
	queue<node> cnt;
	cnt.push(a);
	vis[x][y]=false;
	while(!cnt.empty()){
		node now=cnt.front();
		cnt.pop();
		if(map[now.x][now.y]=='@'){
			ds1[now.x][now.y] = now.time;
		}
		for(int i=0;i<4;i++){
			node end;
			end.x=now.x+xi[i];
			end.y=now.y+yi[i];
			end.time=now.time;
			if(end.x>=0&&end.y>=0&&end.x<n&&end.y<m&&map[end.x][end.y]!='#'&&vis[end.x][end.y]){
				end.time+=11;
				vis[end.x][end.y]=false;
				cnt.push(end);
			}
		}
	}
}
void BFS2(int x,int y){
	node a;
	a.x=x;
	a.y=y;
	a.time=0;
	queue<node> cnt;
	cnt.push(a);
	vis[x][y]=false;
	while(!cnt.empty()){
		node now=cnt.front();
		cnt.pop();
		if(map[now.x][now.y]=='@'){
			ds2[now.x][now.y] = now.time;
		}
		for(int i=0;i<4;i++){
			node end;
			end.x=now.x+xi[i];
			end.y=now.y+yi[i];
			end.time=now.time;
			if(end.x>=0&&end.y>=0&&end.x<n&&end.y<m&&map[end.x][end.y]!='#'&&vis[end.x][end.y]){
				end.time+=11;
				vis[end.x][end.y]=false;
				cnt.push(end);
			}
		}
	}
}
int main(){
	while(~scanf("%d %d",&n,&m)){
		for(int i=0;i<n;i++){
			getchar();
			for(int j=0;j<m;j++){
				scanf("%c",&map[i][j]);
				if(map[i][j]=='Y'){
					xy=i;yy=j;
				}
				if(map[i][j]=='M'){
					xm=i;ym=j;
				}
			}
		}
		MINN=m*n*11;
		memset(ds1,0,sizeof(ds1));
		memset(ds2,0,sizeof(ds2));
		memset(vis,true,sizeof(vis));
		BFS1(xy,yy);
		memset(vis,true,sizeof(vis));
		BFS2(xm,ym);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(MINN>ds1[i][j]+ds2[i][j] && ds1[i][j] && ds2[i][j] )
					MINN = ds1[i][j] + ds2[i][j];
			}
		}
		printf("%d\n",MINN);
	}
	return 0;
}