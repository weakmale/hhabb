#include<cstdio>
#include<queue>
using namespace std;
const int K = 1e6 + 10;
int a[K];
queue <int> q,qq;
typedef long long LL;
int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m) != EOF){
		for(int i = 1; i <= m; i++)
		    scanf("%d",&a[i]),q.push(a[i]);
		for(int i = m + 1; i <= n; i++)
		    scanf("%d",&a[i]),qq.push(a[i]);    
		LL cut = 0;
		while(!q.empty() || !qq.empty()){
			int num = 0;
			while(!q.empty() && num < m){
				int b = q.front(); 	q.pop();
				if(b > 1) qq.push(--b);
				//printf("****%d****",b);
				num++;
			}
		////	printf("\n");
			if(num) cut++;
			num = 0;
			while(!qq.empty() && num < m){
				int b = qq.front();qq.pop();
				if(b > 1) q.push(--b);
				//printf("****%d****",b);
				num++;
			}
				//printf("\n");
			if(num) cut++;
		}
		printf("%lld\n",cut);
	}
	return 0;
}