#include<cstdio>
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	if(n <= k) printf("-1\n");
	else if(n == 1) printf("0\n");
	else if(k == 1) printf("%d\n",n - 1);
	else if(n <= 3) printf("1\n");
	else{
		int p = 0;
		while(n > k) n -= k,p++;
		n = k;
		while(n > 1) n /= 2,p++;
		printf("%d\n",p);
	}
	return 0;
}