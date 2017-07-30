#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int inf=0x3f3f3f3f;
int n;
int map[30][30];
int vis[50];
void init(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j)
				map[i][j]=0;
			else
				map[i][j]=inf;
		}
	}
	memset(vis,0,sizeof(vis));
}
void floyd(){
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
			}
		}
	}
}
int main(){
	while(scanf("%d",&n)!=EOF){
		init();
		for(int i=0;i<n;i++){
			int m,k;
			scanf("%d %d",&m,&k);
			vis[i]=k;
			while(m--){
				int b,c;
				scanf("%d %d",&b,&c);
				if(map[i][b]>c){
					map[i][b]=c;
				}
			}
		}
		floyd();
		int minn=inf;
		for(int i=1;i<n;i++){
			if(vis[i]&&map[0][i]<minn){
				minn=map[0][i];
			}
		}
		printf("%d\n",minn);
	}	
	return 0;
}