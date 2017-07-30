#include<cstdio>
int main(){
	int n,k; scanf("%d %d",&n,&k);
	int p = 0;
	while(n > k){
		if(n % k) p++;
		n -= n % k;
		p += n / k - 1; 
		n /= k;
	}
	p += n - 1;
	if(k==n) puts("-1");
	else 
		printf("%d\n",p);
	return 0;
}