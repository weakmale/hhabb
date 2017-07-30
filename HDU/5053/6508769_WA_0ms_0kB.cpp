#include<cstdio>
__int64 a[10010]={0};
void san(){
	for(int i=0;i<10010;i++)
		a[i]=i*i*i;
}
int main(){
	san();
	int t;scanf("%d",&t);
	int m,n;
	int k=0;
	while(t--){
		__int64 sum=0;
		scanf("%d%d",&m,&n);
		for(int i=m;i<=n;i++){
			sum+=a[i];
		}
		printf("Case #%d: %d\n",++k,sum);
	}
	return 0;
}