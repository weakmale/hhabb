#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXX=202;
const int inf=0x3f3f3f3f;
int n,m;
int map[MAXX][MAXX];
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
	while(~scanf("%d %d",&n,&m)){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				map[i][j]=i==j?0:inf;
			}
		}
		for(int i=0;i<m;i++){
			int a,b,c;
			scanf("%d %d %d" ,&a ,&b ,&c);
			if(c < map[a][b]){
				map[a][b]=c;
				map[b][a]=c;
			}
		}
		floyd();
		int a,b;
		scanf("%d %d",&a,&b);
		if(map[a][b]==inf)
			printf("-1\n");
		else
			printf("%d\n",map[a][b]);
	}
	return 0;
}
