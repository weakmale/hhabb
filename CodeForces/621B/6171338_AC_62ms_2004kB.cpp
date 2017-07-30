#include<cstdio>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int a[2000]={0},b[2000]={0},x,y,sum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			a[x-y+1000]++;
			b[x+y]++;
		}
		for(int i=0;i<2000;i++)
		{
			if(a[i]>1)
				sum+=a[i]*(a[i]-1)/2;
			if(b[i]>1)
				sum+=b[i]*(b[i]-1)/2;
		}
		printf("%d",sum);
	}
	return 0;
}