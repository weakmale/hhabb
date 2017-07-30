#include<cstdio>
#include<map>
using namespace std;
const int K = 2e3 + 10;
int a[K],dp[K][K];
map <int,int> mm;
int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m) != EOF){
		for(int i = 1; i <= n; i++)
		    scanf("%d",&a[i]);
		for(int i = 1; i <= n; i++){
		   mm.clear();
		   int num = 0;
		    for(int j = i; j <= n; j++){
		    	if(!mm[a[j]]) mm[a[j]]++,num++;
		    	dp[i][j] = num;
			}
		}
		int q,l,r;
		scanf("%d",&q);
		while(q--){
			scanf("%d %d",&l,&r);
			printf("%d\n",dp[l][r]);
		}
	}
	return 0;
}