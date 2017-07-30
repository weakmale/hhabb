#include<cstdio>
int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int a,b,sum[2]={0};
		scanf("%d%d",&a,&b);
		for(int i=1;i<a;i++)
		{
			if(a%i==0)
				sum[0]=sum[0]+i;
		}
		for(int i=1;i<b;i++)
		{
			if(b%i==0)
				sum[1]=sum[1]+i;
		}
		if(sum[0]==b&&sum[1]==a)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}