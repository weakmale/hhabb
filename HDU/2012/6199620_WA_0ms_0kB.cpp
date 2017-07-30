#include<cstdio>
#include<math.h>
int main()
{
	int x,y;
	while(scanf("%d%d",&x,&y)!=EOF)
	{	int k=0,n,m=0;
		for(int i=x;i<=y;i++)
		{
			n=i*i+i+41;
			m=sqrt(n);
			for(int j=2;j<m;j++)
				if(n%j==0)
					k=1;
		}
		if(k)
			printf("Sorry\n");
		else
			printf("OK\n");
	}
	return 0;
}