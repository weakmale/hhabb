#include<cstdio>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int a[n],max=0,t=0,k=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]>max)
				max=a[i];
		}
		for(int i=1;t<n;i++)
		{
			k=max*i;t=0;
			for(int j=0;j<n;j++)
				if(k%a[j]==0)
					t++;
		}
		printf("%d\n",k);
	}
	return 0;
 } 