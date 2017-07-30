#include<cstdio>
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	if(n == 1) printf("-1\n");
	else if(n == 2) printf("%d\n",m - 1);
	else if(n == 3 || n == 4) printf("%d\n",m - 3);
	else printf("%d\n",m - m / 2);
	return 0;
}