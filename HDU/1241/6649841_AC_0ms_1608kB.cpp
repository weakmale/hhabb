#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
using namespace std;
int m,n;
int ans=0;
char map[150][150];
bool vis[150][150];
struct node{
	int x;
	int y;
};
int xi[8]={1,-1,0,0,1,1,-1,-1};
int yi[8]={0,0,1,-1,1,-1,1,-1};
void BFS(int x1,int y1){
	node a;
	a.x=x1;
	a.y=y1;
	queue<node> cnt;
	cnt.push(a);
	while(!cnt.empty()){
		node now;
		now=cnt.front();
		cnt.pop();
		for(int i=0;i<8;i++){
			node end;
			end.x=now.x+xi[i];
			end.y=now.y+yi[i];
			if(end.x>=0&&end.y>=0&&end.x<m&&end.y<n&&map[end.x][end.y]=='@'){
				
				map[end.x][end.y]='*';
				cnt.push(end);
			}
			
		}
	}
}
int main(){
	while(~scanf("%d%d",&m,&n),n||m){
		 for(int i=0;i<m;i++)
			scanf("%s",map[i]);
		int t=0;
		ans=0;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++)
			{	
				if(map[i][j]=='@'){
					map[i][j]='*';
					BFS(i,j);
					ans++;
				}	
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}