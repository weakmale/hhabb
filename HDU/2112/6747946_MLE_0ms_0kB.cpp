#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int inf=0x3f3f3f3f;
const int MAXX=10010;
char str[155][33];
int map[MAXX][MAXX];
int n;
void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)
				map[i][j]=0;
			else
				map[i][j]=inf;
		}
	}
}
bool vis[MAXX];
int dis[MAXX];
void dijkstra()
{
	memset(vis,0,sizeof(vis));
	vis[1]=1;
	for(int i=2;i<=n;i++)
		dis[i]=map[1][i];
	for(int i=0;i<n;i++)
	{
		int M=inf,k=-1;
		for(int j=1;j<=n;j++)
		{
			if(!vis[j]&&dis[j]<M)
			M=dis[j],k=j;
		}
		if(k==-1)
		return ;
		vis[k]=1;
		for(int j=1;j<=n;j++)
			if(!vis[j]&&dis[j]>dis[k]+map[k][j])
			dis[j]=dis[k]+map[k][j];
	}
}
int main(){
	while(~scanf("%d",&n),n!=-1){
		init();
		char a[35];
		char b[35];
		int c;
		scanf("%s %s",a,b);
		strcpy(str[1],a);
		strcpy(str[2],b);
		int t=3;
		for(int i=0;i<n;i++){
			scanf("%s %s %d",a,b,&c);
			int x=0,y=0;
			for(int j=1;j<t;j++){
				if(strcmp(a,str[j])==0)
					x=j;
				if(strcmp(b,str[j])==0)
					y=j;
//				cout<<str[j]<<"~~~"<<j<<"~~~"<<x<<"~~~~"<<y<<endl;
			}
			if(x==0){
				x=t;  strcpy(str[t],a); t++;
			}
			if(y==0){
				y=t;  strcpy(str[t],b); t++;
			}
			if(map[x][y]>c){
				map[x][y]=map[y][x]=c;	
			}
		}
		dijkstra();
		printf("%d\n",dis[2]);
	}
	return 0;
}