#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int q;
int num[100011]={0};
int judge(int mid){
	for(int i=q;i<=mid;i++)
		if(num[i]==0)
			return false;
	return true;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		memset(num,0,sizeof(num));
		int l;
		int maxx=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&l);
			num[l]=l;
			if(l>maxx)
			maxx=l;
		}
		for(int i=0;i<n;i++){
			scanf("%d",&q);
			int l=q,r=maxx+1;
			int ans=0;
			while(l<=r){
				int mid=(l+r)>>1;
				if(judge(mid)){
					
					l=mid+1;
				}
				else {
					ans=mid;
					r=mid-1;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}