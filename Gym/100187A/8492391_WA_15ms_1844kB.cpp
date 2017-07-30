#include<cstdio>
int main(){
	int n,k; scanf("%d %d",&n,&k);
	if(k == n) {puts("-1"); return 0;}
	if(n == 1) printf("0\n");
	else if(k == 1) printf("%d\n",n - 1);
	else if(n <= 3){
	printf("1\n");
	}
	else{
		int p = 0;
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