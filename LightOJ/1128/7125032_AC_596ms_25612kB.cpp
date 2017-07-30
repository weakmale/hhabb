#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int POW = 18;
const int maxn = 100010;
vector<int> edge[maxn];
int val[maxn];
int f[maxn][POW];
int dp[maxn][POW];
void dfs(int u){
	int sz=edge[u].size();
	for(int i=0;i<sz;i++){
		int v=edge[u][i];
		f[v][0]=u;
		dp[v][0]=val[v];
		for(int j=1;j<POW;j++) f[v][j]=f[f[v][j-1]][j-1];
		for(int j=1;j<POW;j++) dp[v][j]=max(dp[v][j-1],dp[f[v][j-1]][j-1]);
		dfs(v);
	}
}
int solve(int s,int v){
	for(int i=POW-1;i>=0;i--){
		if(dp[f[s][i]][i]>=v)
			s=f[s][i];
	}
	return s;
}
int main(){
	int t,ca=1,n,q;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&q);
		for(int i=0;i<n;i++) edge[i].clear();
		val[0]=1;
		for(int i=0;i<POW;i++)dp[0][i]=val[0],f[0][i]=0;
		for(int i=1,fa;i<n;i++){
			scanf("%d%d",&fa,&val[i]);
			edge[fa].push_back(i);
		}
		dfs(0);
		int s,v;
		printf("Case %d:\n",ca++);
		while(q--){
			scanf("%d%d",&s,&v);
			printf("%d\n",solve(s,v));
		}
	}
	return 0;
}