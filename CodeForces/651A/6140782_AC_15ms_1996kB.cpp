#include<cstdio> 
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		int t=0;
		if(a==1&&b==1)
			printf("0\n");
		else
		{
			while(a>0&&b>0)
			{
			
				if(a>b)
				{
					a-=2;
					b++;
				}
				else
				{
					a++;
					b-=2;
				}
					t++;
			}
			printf("%d\n",t);
		}
	}
	return 0;
}