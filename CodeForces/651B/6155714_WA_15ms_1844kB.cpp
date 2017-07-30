#include<cstdio>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int a[n],k=0,min=0,x=0;
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		min=a[0];
		for(int i=0;i<n;i++)
		{
			k=i;
			for(int j=i+1;j<n;j++)
				if(a[j]<a[k])
					k=j;
			if(k!=i)
			{
				x=a[k];
				a[k]=a[i];
				a[i]=x;
			}
		}
		k=0;
		for(int i=0;i<n-1;i++)
		{
			if(a[i]==a[i+1])
			{
				for(int j=i+1;j<n-1;j++)
				{
					if(a[i+1]<a[j]&&a[j]==a[j+1])
					{
						x=a[i+1];
						a[i+1]=a[j];
						a[j]=x;	
						break; 
					}
				}
			}
			if(a[i+1]>a[i])
				k++;
		}
		printf("%d\n",k);
	}
	return 0;
} 