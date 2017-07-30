#include<cstdio>
__int64 GCD(__int64 a,__int64 b){
	if(a==1||b==1)
		return 1;
	else if(a==b)
		return a;
	else if( a%b==0 ){
		return a/b;}
	else 
		return GCD(b,a%b);
}
__int64 LCM(__int64 a,__int64 b){
	return a*b/GCD(a,b);
}

int main(){
	int t;
	scanf("%d",&t);
	__int64 m,n;
	while(t--){
		scanf("%I64d %I64d",&m,&n);
		__int64 k=LCM(m,n);
		if(k/m==n)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}