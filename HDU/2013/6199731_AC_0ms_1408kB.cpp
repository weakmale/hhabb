#include<cstdio>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int sum=1;
		while(--n)
			sum=(sum+1)*2;
		printf("%d\n",sum);
	}
	return 0;
 } 