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
queue< node > cnt;
void BFSF(){
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
			if(end.x>=0&&end.x<r&&end.y>=0&&end.y<c&&vis[end.x][end.y]&&(map[end.x][end.y]=='.'||map[end.x][end.y]=='J')){
				if(F[end.x][end.y]<=end.t)
					continue;
				
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
		while(!cnt.empty())
			cnt.pop();
		int ans=0;
		while(!cnt.empty())
			cnt.pop();
			scanf("%d%d",&r,&c);
		for(int i=0;i<r;i++)
			scanf("%s",map[i]);
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				F[i][j]=1000000007;
				if(map[i][j]=='J'){
					xj=i;yj=j;
				}
				if(map[i][j]=='F'){
					xf=i;yf=j;
					F[xf][yf]=0;
					vis[xf][yf]=false;
					node a;
					a.x=xf;
					a.y=yf;
					a.t=0;
					cnt.push(a);
				}
			}
		}
		memset(vis,true,sizeof(vis));
		BFSF();
		memset(vis,true,sizeof(vis));
		vis[xj][yj]=false;
		node b;
		b.x=xj;
		b.y=yj;
		b.t=0;
		while(!cnt.empty())
			cnt.pop();
		cnt.push(b);
		ans=BFSJ();
		if(ans==-1)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}