#include<cstdio>
int main()
{
	int n,m;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		int a[1000]={ 0 },i=0;
		while(m<=n)
		{
			int sum=0,s;
			s=m;
			while(s>0)
			{
				int x;
				x=s%10;
				sum=sum+(x*x*x);
				s=s/10;
			}
			if(sum==m){a[i]=sum;i++;}
			m++;
		}
		if ( a[0]==0)
			printf("no\n");
		else
		{	for(int i=0;a[i]>0;i++)
				printf("%d ",a[i]); printf("\n");}
	}
	return 0;
}