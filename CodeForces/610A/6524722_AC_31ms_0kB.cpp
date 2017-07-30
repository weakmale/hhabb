#include<cstdio>
int main(){
	long long n;
	scanf("%lld",&n);
	if(n%2==0)
		printf("%lld\n",(n/2-1)/2);
	else
		printf("0\n");
	return 0;
}