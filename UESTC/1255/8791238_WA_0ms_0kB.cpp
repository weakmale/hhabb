#include<cstdio>
#include<algorithm>
using namespace std;
const int K = 1e6 + 10;
typedef long long LL;
LL a[K];
int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m) != EOF){
		for(int i = 1; i <= n; i++)
		    scanf("%lld",&a[i]);
		LL cut = 0;
		sort(a + 1,a + 1 + n);
	    if(n < m){
	    	for(int i = 1; i <= n; i++)
	    	    cut = max(cut,a[i]);
	    	printf("%lld\n",cut);
		}
		else{
			int p = n - m;
			for(int i = 1,j = p * 2; i < j; i++,j--)
			    cut = max(cut,a[i] + a[j]);
			for(int i = p * 2 + 1; i <= n; i++)
			    cut = max(cut,a[i]);
			printf("%lld\n",cut);
		}
	}
	return 0;
}