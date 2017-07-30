#include<cstdio>
#include<math.h>
int main()
{
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		int a[m][n],max=0,h=0,l=0;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{	
				scanf("%d",&a[i][j]);
				if(abs(a[i][j])>abs(max))
				{	max=a[i][j]; h=i;l=j;}
			}
		}
		printf("%d %d %d\n",h+1,l+1,max);
	}
	return 0;
}