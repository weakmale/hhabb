#include<cstdio>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		double x[n],y[n];
		int sum=0;
		for(int i=0;i<n;i++)
			scanf("%lf%lf",&x[i],&y[i]);
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
				if((((y[i]-y[j])/(x[i]-x[j]))==1)||(((y[i]-y[j])/(x[i]-x[j])))==-1)
					sum++;
		}
		printf("%d\n",sum);
	} 
}