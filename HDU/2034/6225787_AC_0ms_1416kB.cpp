#include<cstdio>
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
			break;
	int  a[101],b[101],k=0,l=0,x,c[101];
	for(int i=0;i<n+m;i++)
	{
		scanf("%d",&x);
		if(i<n)
			a[i]=x;
		else{
				b[l]=x;
				l++;
		}
	}l=0;
	for(int i=0;i<n;i++)
	{
		int t=1;
		for(int j=0;j<m;j++)
		{
			if(a[i]==b[j])
			{
				k++;
				t=0;
				break;
			}
		}
		if(t)
		{
			c[l]=a[i];
			l++;
		}
	}
	if(k==n)
		printf("NULL");
	else
	{
		int temp;
		for(int i=0;i<l;i++)
		{
			for(int j=i;j<l;j++)
			{	
				if(c[i]>c[j])
				{
					temp=c[i];
					c[i]=c[j];
					c[j]=temp;
				}
			}
		}
			for(int i=0;i<l;i++)
				printf("%d ",c[i]);
	}
		printf("\n");
	}
return 0;
}