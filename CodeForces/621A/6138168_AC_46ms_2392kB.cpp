#include<cstdio>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int a[100000];
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		long long sum=0,min=0;
		min=a[0];
		for(int i=0;i<n;i++)
		{
			sum+=a[i];
			if(a[i]%2==1)
				min=a[i];
		}
		if(sum%2==0)
			printf("%lld",sum);
		else
		{
			for(int i=0;i<n;i++)
				if(a[i]%2==1)
					if(a[i]<min)
						min=a[i];
			printf("%lld",sum-min);
		}
	}
	return 0;
}