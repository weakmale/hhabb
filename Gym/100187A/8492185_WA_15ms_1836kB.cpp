#include<cstdio>
int main(){
	int n,k; scanf("%d %d",&n,&k);
	int p = 0;
	if(k == n) {puts("-1"); return 0;}
	//if(n % k) p++,n -= n % k; 
	if(k == 1) printf("%d\n",n-1);
	else if(n <= 3){
	printf("1\n");
	}
	else{
	while(n > k){
		n -= k;
		p++;
	}
	n = k;
	while(n > 3){
		if(n % 2) n++;
		n /= 2;
		p++;
	}
	printf("%d\n",++p);
}
	return 0;
}