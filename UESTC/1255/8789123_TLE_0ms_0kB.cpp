#include<cstdio>
#include<queue>
using namespace std;
const int K = 1e6 + 10;
int a[K];
priority_queue<int> q,qq;
typedef long long LL;
int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m) != EOF){
		for(int i = 1; i <= n; i++)
		    scanf("%d",&a[i]),q.push(a[i]);  
		LL cut = 0;
		while(!q.empty() || !qq.empty()){
			int num = 0;
			while(!q.empty() && num < m){
				int b = q.top(); 	q.pop();
				if(b > 1) qq.push(--b);
				num++;
			}
			if(num) cut++;
			while(!q.empty()) qq.push(q.top()),q.pop();
			num = 0;
			while(!qq.empty() && num < m){
				int b = qq.top();qq.pop();
				if(b > 1) q.push(--b);
				num++;
			}
			while(!qq.empty()) q.push(qq.top()),qq.pop();
			if(num) cut++;
		}
		printf("%lld\n",cut);
	}
	return 0;
}