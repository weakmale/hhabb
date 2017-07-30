#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=555;
long long  A[MAXN];
long long B[MAXN];
long long C[MAXN];
long long x;
long long cnt[MAXN*MAXN];
int L,N,M;
int main(){
	int t=1;
	int S;
	while(~scanf("%d %d %d",&L,&N,&M)){
		for(int i=0;i<L;i++)
			scanf("%lld",&A[i]);
		for(int i=0;i<N;i++)
			scanf("%lld",&B[i]);
		for(int i=0;i<M;i++)
			scanf("%lld",&C[i]);
		int s=0;
		for(int i=0;i<L;i++)
			for(int j=0;j<N;j++)
				cnt[s++]=A[i]+B[j];
		scanf("%d",&S);
		sort(cnt,cnt+s);
		printf("Case %d:\n",t++);
		while(S--){
			scanf("%lld",&x);
			bool k=false;
			for(int i=0;i<M;i++){
				int l=0,r=s-1;
				while(l<=r){
					int mid=(l+r)/2;
					if(C[i]+cnt[mid]==x){
							k=true;break;
					}
					else if(cnt[mid]+C[i]<x){
						l=mid+1;
					}
					else{
						r=mid-1;
					
				}
				if(k)
					break;
			}
		}
		if(k)
			printf("YES\n");
		else
			printf("NO\n");
		}
	}
	return 0;
}