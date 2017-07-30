#include<cstdio>
int slove(int n,int m,int mod){
	int ans=1;
	int beas=n%mod;
	while(m){
		if(m%2==1){
			ans=(ans*beas)%mod;
		}
		beas=(beas*beas)%mod;
		m>>=1;
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