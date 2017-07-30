#include<cstdio>
int main()
{
	int n;scanf("%d",&n);getchar();
	while(n--)
	{
		char a[10000];
		gets(a);
		int i=1,t=0;
		while(a[i])
		{
			if(a[i-1]<0)
			{
				t++; i++;
			}
			i++;
		}
		printf("%d\n",t);
	}
	return 0;
}