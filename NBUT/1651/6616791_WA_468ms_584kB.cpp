#include<cstdio>
int n,m,k;
int num[100011];
int sum;
bool judge(int mid){
	for(int i=0;i<k;i++)
	{
		if(num[i]>=mid){
			return true;}
	}
	return mid<=sum-mid-n+k+1;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		sum=m;
		int max=0;
		for(int i=0;i<k;i++){
			scanf("%d",&num[i]);
			if(num[i]>max)
				max=num[i];
			sum-=num[i];
		}
		if(max>=sum-n+k+1){
			printf("Impossible\n");
			continue;
		}
		int l=0,r=sum;
		while(l<=r){
			int mid=(l+r)>>1;
			if(judge(mid)){
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		printf("%d\n",l);
	}
}