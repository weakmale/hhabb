#include<cstdio>
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		int i=0,t=0;
		char s[100];
		if(a<0)
		{
			a=-a;
			t=1;
		}
		while(a)
		{
			if(a%b>9)
			  s[i]=a%b-10+'A';
			else
				s[i]=a%b+'0';
			i++;
			a=a/b;
		}
		if(t)
			printf("-");
		while(i--){
			printf("%c",s[i]);}
		printf("\n");
	}
	return 0;
}