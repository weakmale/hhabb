#include<cstdio> 
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		int t=0;
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
		printf("%d",t);
	}
	return 0;
}