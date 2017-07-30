#include<cstdio>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int a[30][30]={0};a[0][0]=1;a[1][0]=1;a[1][1]=1;
		for(int i=2;i<n;i++)
		{
			for(int j=0;j<=i;j++)
			{
				if(j==0||j==i)
					a[i][j]=1;
				else
					a[i][j]=a[i-1][j-1]+a[i-1][j];
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=i;j++)
			{
				if(j)
					printf(" ");
				printf("%d",a[i][j]);
			}
				printf("\n");
		}
		printf("\n");
	}
	return 0;
}