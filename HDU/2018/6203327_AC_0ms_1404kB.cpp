#include<cstdio>
int niu(int n)
{
	if(n<4)
		return n;
	else
		return niu(n-1)+niu(n-3);
}
int main()
{
	int n;
	while(scanf("%d",&n)&&n!=0)
	{
		printf("%d\n",niu(n));
	}
	return 0;
}