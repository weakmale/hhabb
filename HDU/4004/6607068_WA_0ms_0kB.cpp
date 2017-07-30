#include<cstdio>
#include<algorithm>
using namespace std;
int L,n,m;
int len[500555];
bool judge(int mid){
	int ln=0;
	int cnt=0;
	for(int i=0;i<n;){
		if(len[i]<ln+mid){
			i++;
		}
		else{
			if(ln==len[i-1])
				return true;
			ln=len[i-1];cnt++;
		}
	}
	cnt ++;
	return cnt > m;
}
int main(){
	while(~scanf("%d %d %d",&L,&n,&m)){
		for(int i=0;i<n;i++)
			scanf("%d",&len[i]);
		sort(len,len+n);
		int l=0,r=L;
		int ans;
		while(l<=r){
			int mid=(l+r)/2;
			if(judge(mid)){
				l=mid+1;
			}
			else{
				ans=mid;
				r=mid-1;
				
			}
		}
		printf("%d\n",ans+1);
	}
}