#include<cstdio>
int Eular(int n){
	int  res=n,i;
	for(i=2;i*i<=n;i++){
		if(n%i==0){
			res=res/i*(i-1);
		}
		while(n%i==0)
			n/=i;
	}
	if(n>1)
		return res/n*(n-1);
	else
		return res;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		printf("%d\n",Eular(n));
	}
	return 0;
}