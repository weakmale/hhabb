#include<cstdio>
int main(){
	int t;scanf("%d",&t);
	__int64 m,n;
	int k=0;
	while(t--){
		__int64 sum=0;
		scanf("%I64d%I64d",&m,&n);
		__int64 i;
		for( i=m;i<=n;i++){
			sum+=i*i*i;
		}
		printf("Case #%d: %I64d\n",++k,sum);
	}
	return 0;
}