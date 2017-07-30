#include<cstdio>
const int mod=9973;
int x,y;
int EXGCD(int a,int b){
	if(b==0){
		x=1; y=0;return a;
	}
	int r=EXGCD(b,a%b);
	int t=x;
	x=y;
	y=t-a/b*y;
	return r;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n;int B; 
		scanf("%d %d",&n,&B);
		EXGCD(B,mod);
		x=(x%mod+mod)%mod;
		printf("%d\n",(n*x)%mod);
	}
}