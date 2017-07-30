#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int n,k;
bool vis[200100];
struct node{
	int x;
	int time;
};
queue<node> cnt;
int  BFS(){
	while(!cnt.empty()){
		node now=cnt.front();
		cnt.pop();
		if(now.x==k){;
			return now.time;
		}
		if(now.x<=k&&vis[now.x+1]){
			node end;
			end.x=now.x+1;
			end.time=now.time+1;
			vis[end.x]=false;
			cnt.push(end);
		}
		if(now.x>=1&&vis[now.x-1]){
			node end;
			end.x=now.x-1;
			end.time=now.time+1;
			vis[end.x]=false;				
			cnt.push(end);
		}
		if(now.x<=k&&vis[now.x*2]){
			node end;
			end.x=now.x*2;
			end.time=now.time+1;
			vis[end.x]=false;
			cnt.push(end);
		}
	}
}
int main(){
	while(~scanf("%d %d",&n,&k)){
		memset(vis,true,sizeof(vis));
		while(!cnt.empty()) cnt.pop();  	
		vis[n]=1;
		node a;
		a.time=0;
		a.x=n;
		cnt.push(a);
		printf("%d\n",BFS());
	}
	return 0;
}