#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int q;
int num[100011]={0};
int b[100011]={0};
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		memset(num,0,sizeof(num));
		memset(b,0,sizeof(b));
		int l;
		int maxx=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&l);
			num[l]++;
			if(l>maxx)
				maxx=l;
		}
		int  k=0;
		for(int i=1;i<=maxx+1;i++){
			if(num[i]==0)
				b[k++]=i;
		}
		for(int i=0;i<n;i++){
			scanf("%d",&q);
			int l=0,r=k;
			int ans=0;
			if(num[q]==0)
			{
				printf("%d\n",q);
				continue;
			}
			while(l<=r){
				int mid=(l+r)>>1;
				if(b[mid]>=q){
					ans=mid;
					r=mid-1;
				}
				else {
					l=mid+1;
					
				}
			}
			printf("%d\n",b[ans]);
		}
	}
	return 0;
}
	
