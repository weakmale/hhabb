#include<cstdio>
int main()
{
	int n;
	while(scanf("%d",&n)&&n!=0)
	{
		int mny,x=0;
		while(n--)
		{
			scanf("%d",&mny);
			x=x+(mny/100); mny=mny%100;
			x=x+(mny/50); mny=mny%50;
			x=x+(mny/10); mny=mny%10;
			x=x+(mny/5);mny=mny%5;
			x=x+(mny/2);mny=mny%2;
			if(mny>0)
			x++;
		}
		printf("%d\n",x);
	}
}