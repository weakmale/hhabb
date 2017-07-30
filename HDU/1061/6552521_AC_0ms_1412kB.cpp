#include<cstdio>
int slove(int n,int m,int mod){
	int ans=1;
	int beas=n%mod;//进行求余 
	while(m){//把m级别的复杂度转化为log2(m)的优化转化为((((beas)^2)^2)^2) *ans
		if(m%2==1){
			ans=(ans*beas)%mod;
		}
		beas=(beas*beas)%mod;
		m>>=1;//这个是移位相当于m/2 
	}
	return ans;
}
int main(){
	int n,m,mod,T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		m=n;
		mod=10;
		printf("%d\n",slove(n,m,mod));
	}
	return 0;
}