#include<stdio.h>
int main()
{
	int m,n;
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		int a,b,c,j=0;
		for(int i=m;i<=n;i++)
		{
			a=i/100;
			b=i%100/10;
			c=i%10;
			if( (a*a*a) + (b*b*b) + (c*c*c) ==i )
			{
				if(j) printf(" ");	
				j++;
				printf("%d",i);
				
			}
		}
		if(j==0)
			printf("no");
		printf("\n");
	}
	return 0;
}
