#include<cstdio>
int main(){
	int n,k; scanf("%d %d",&n,&k);
	int p = 0;
	if(k == n) {puts("-1"); return 0;}
	while(n / 2 > k){
		if(n % k) p++,n -= n % k;
		p += n / k - 1; 
		n /= k;
	}
	while(n > 1){
		if(n % 2) n++;
		n /= 2;
		p++;
	}
	printf("%d\n",p);
	return 0;
}