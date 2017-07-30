#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXX=1002;
int n;
double map[MAXX][MAXX];
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
			}
		}
	}
}
int main(){
	while(~scanf("%d",&n)){
		memset(map,0,sizeof(map));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%lf",&map[i][j]);
			}
		}
		floyd();
		int m;
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			if(map[a][b])
				printf("%.3lf\n",map[a][b]);
			else
				printf("What a pity!\n");
		}
	}
	return 0;
}