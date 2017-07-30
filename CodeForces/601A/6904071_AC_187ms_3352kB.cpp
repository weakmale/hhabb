#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
const int inf=0x3f3f3f;
const int MAXX=410;
int Map1[MAXX][MAXX];
int Map2[MAXX][MAXX];
int n,m;
void init(){
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1;j <= n; ++j)
        {
            Map1[i][j]=inf;
            if( i == j )
                Map1[i][j]=0;
        }
    }
}
void Floyd(){
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; j++){
            if(i==j)
                Map2[i][j]=0;
            else
                if( Map1[i][j] == inf )
                    Map2[i][j] = 1;
                else
                    Map2[i][j] = inf;
//            printf("%d %d %d\n",Map2[i][j],i,j);
        }
    }
    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i ){
            for(int j = 1; j <= n; ++j){
                Map1[i][j] = min( Map1[i][j], Map1[i][k] + Map1[k][j]);
                Map2[i][j] = min( Map2[i][j], Map2[i][k] + Map2[k][j]);
            }
        }
    }
}
int main(){
	scanf("%d %d",&n, &m);
	init();
	for(int i = 1;i <= m; ++i ){
        int a; int b;
        scanf("%d %d", &a, &b);
        Map1[a][b] = Map1[b][a] = 1;
	}
	int ans = 0; int cnt = 0;
	Floyd();
	ans = Map1[1][n];
	cnt = Map2[1][n];
//	printf("%d %d\n",Map1[1][n],Map2[1][n]);
	if( ans !=inf && cnt != inf )
        printf("%d\n", max ( ans, cnt ) );
	else
        printf("-1\n");
	return 0;
}
