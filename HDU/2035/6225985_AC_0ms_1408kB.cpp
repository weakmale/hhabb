#include<cstdio>
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)&&(n!=0||m!=0))
	{
		int sum=0; sum=n%1000;
		for(int i=1;i<m;i++)
		{
			sum=sum*n;
			sum=sum%1000;
		}
		printf("%d\n",sum);
	}
	return 0;
 } 