#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int N,M,a[510][510],ok,vis[510][510];
char s[510];
struct node{
	int x,y;
};
int xx[4] = {0,0,-1,1};
int yy[4] = {1,-1,0,0};
void bfs(){
	queue <node> q;
	node u;
	u.x = u.y = 1;
	q.push(u);
	while(!q.empty()){
		u = q.front();
		q.pop();
		if(u.x == N && u.y == M){
			ok = 1;
			break;
		}
		for(int i = 0; i < 4; i++){
			int fx = u.x + xx[i];
			int fy = u.y + yy[i];
			if(fx >= 1 && fx <= N && fy >= 1 && fy <= M){
				if(!vis[fx][fy]){
					vis[fx][fy] = 1;
					if(!a[fx][fy]){
						node v;
						v.x = fx;
						v.y = fy;
						q.push(v);
					}
				}
			}
		}
	}
}
int main()
{
	scanf("%d %d",&N,&M);
	for(int i = 1; i <= N; i++){
		scanf("%s",s + 1);
		int nl = strlen(s + 1);
		for(int j = 1; j <= nl; j++)
		    if(s[j] == '#')
		        a[i][j] = 1;
	}
	for(int i = 1; i <= N; i++){
		scanf("%s",s + 1);
		int nl = strlen(s + 1);
		for(int j = 1; j <= nl; j++)
		    if(s[j] == '#')
		        a[i][j] = 1;
	}
	ok = 0;
	vis[1][1] = 1;
	bfs();
	if(ok) printf("YES\n");
	else printf("NO\n");
//	for(int i = 1; i <= N; i++){
//		for(int j = 1; j <= M; j++)
//		    printf("%d ",a[i][j]);
//		printf("\n");
//	}
	return 0;
}