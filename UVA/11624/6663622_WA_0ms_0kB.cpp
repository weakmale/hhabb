#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int r,c;
int xj;
int yj;
int xf;
int yf;
char map[1100][1100];
int F[1100][1100];
bool vis[1100][1100];
struct node{
	int x;
	int y;
	int t;
};
int xi[4]={1,-1,0,0};
int yi[4]={0,0,1,-1};
void BFSF(){
	node a;
	a.x=xf;
	a.y=yf;
	a.t=0;
	queue<node>cnt;
	cnt.push(a);
	while(!cnt.empty()){
		node now=cnt.front();
		cnt.pop();
		for(int i=0;i<4;i++){
			node end;
			end.x=now.x+xi[i];
			end.y=now.y+yi[i];
			end.t=now.t+1;
			if(end.x>=0&&end.x<r&&end.y>=0&&end.y<c&&vis[end.x][end.y]&&(map[end.x][end.y]=='.'||map[end.x][end.y]=='J')){
				vis[end.x][end.y]=false;
				F[end.x][end.y]=end.t;
				cnt.push(end);
			}
		}
	}
}
int BFSJ(){
	node a;
	a.x=xj;
	a.y=yj;
	a.t=0;
	queue<node> cnt;
	while(!cnt.empty())
		cnt.pop();
	cnt.push(a);
	while(!cnt.empty()){
		node now=cnt.front();
		cnt.pop();
		if(now.x<=0||now.x==r-1||now.y<=0||now.y==c-1)
            return now.t+1;
		for(int i=0;i<4;i++){
			node end;
			end.x=now.x+xi[i];
			end.y=now.y+yi[i];
			end.t=now.t+1;
			if(end.x>=0&&end.x<r&&end.y>=0&&end.y<c&&vis[end.x][end.y]&&(map[end.x][end.y]=='.'||map[end.x][end.y]=='J')&&F[end.x][end.y]>end.t){
				vis[end.x][end.y]=false;
				cnt.push(end);
			}
		}	
	}
	return -1;
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int cnt=0;
		scanf("%d%d",&r,&c);
		for(int i=0;i<r;i++)
			scanf("%s",map[i]);
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(map[i][j]=='J'){
					xj=i;yj=j;
				}
				if(map[i][j]=='F'){
					xf=i;yf=j;
				}
			}
		}
		memset(vis,true,sizeof(vis));
		memset(F,1000000007,sizeof(F));
		vis[xf][yf]=false;
		F[xf][yf]=0;
		BFSF();
		memset(vis,true,sizeof(vis));
		vis[xj][yj]=false;
		cnt=BFSJ();
		if(cnt==-1)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n",cnt);
	}
	return 0;
}