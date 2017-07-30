#include<cstdio>
int main(){
	int n,k; scanf("%d %d",&n,&k);
	int p = 0;
	if(k == n) {puts("-1"); return 0;}
	//if(n % k) p++,n -= n % k; 
	while(n > k){
		n -= k;
		p++;
	}
	p += n / 3;
	if(n % 3 && n != 1) p++;
//	if(n != 1) p++;
	printf("%d\n",p);
	return 0;
}