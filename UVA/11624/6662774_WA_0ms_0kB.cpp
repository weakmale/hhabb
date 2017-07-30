#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int r,c;
int xj;
int yj;
int xf;
int yf;
char map[1020][1020];
int F[1020][1020];
bool vis[1020][1020];
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
			end.t=now.t;
			if(end.x>=0&&end.x<r&&end.y>=0&&end.y<c&&vis[end.x][end.y]&&map[end.x][end.y]!='#'){
				vis[end.x][end.y]=false;
				end.t++;
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
	cnt.push(a);
	while(!cnt.empty()){
		node now=cnt.front();
		cnt.pop();
		
		if(now.x-1<0||now.x+1>=r||now.y-1<0||now.y+1>=c)
        {
            return now.t+1;
        }
		for(int i=0;i<4;i++){
				node end;
			end.x=now.x+xi[i];
			end.y=now.y+yi[i];
			end.t=now.t;
			if(end.x>=0&&end.x<r&&end.y>=0&&end.y<c&&vis[end.x][end.y]&&map[end.x][end.y]!='#'&&F[end.x][end.y]!=end.t+1){
				vis[end.x][end.y]=false;
				end.t+=1;
				cnt.push(end);
			}
		}	
	}
	return 0;
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
		memset(F,-1,sizeof(F));
		vis[xf][yf]=false;
		F[xf][yf]=0;
		BFSF();
		memset(vis,true,sizeof(vis));
		vis[xj][yj]=false;
		cnt=BFSJ();
		if(cnt)
			printf("%d\n",cnt);
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}