#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int m,n;
char map[250][250];
int x,y;
struct node{
	int x1;
	int y1;
	int time;
	bool friend operator < (node a,node b){
		return a.time>b.time;
	}
};
int xi[4]={1,-1,0,0};
int yi[4]={0,0,-1,1};
int BFS(){
	node a;
	a.x1=x;
	a.y1=y;
	a.time=0;
	priority_queue<node> cnt;
	cnt.push(a);
	
	while(!cnt.empty()){
		node now=cnt.top();
		cnt.pop();
		if(map[now.x1][now.y1]=='a')
			return now.time;
		map[now.x1][now.y1]='#';
		for(int i=0;i<4;i++){
			node end;
			end.x1=now.x1+xi[i];
			end.y1=now.y1+yi[i];
			end.time=now.time;
			if(map[end.x1][end.y1]!='#'&&end.x1>=0&&end.y1>=0&&end.x1<m&&end.y1<n){
				if(map[end.x1][end.y1]=='x')
					end.time+=2;
				else
					end.time+=1;
				cnt.push(end);
			}
		}
	}
	return 0;
}
int main(){
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++){
		scanf("%s",map[i]);
		for(int j=0;j<n;j++){	
			if(map[i][j]=='r'){
				x=i;y=j;
			}
		}
	}
	int ans=BFS();
	if(ans)
		printf("%d\n",ans);
	else
		printf("Poor ANGEL has to stay in the prison all his life.\n");
	return 0;
}