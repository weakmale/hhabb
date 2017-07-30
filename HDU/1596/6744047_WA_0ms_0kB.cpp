#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXX=1001;
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
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				map[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				double a;
				scanf("%lf",&a);
				map[i][j]=a;
			}
		}
		floyd();
		int m;
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			if(map[a][b]==0.0)
				printf("What a pity!\n");
			else
				printf("%.3lf\n",map[a][b]);
		}
	}
	return 0;
}