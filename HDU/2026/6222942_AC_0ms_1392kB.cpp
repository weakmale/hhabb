#include<cstdio>
int main()
{
	char str[100];
	while(gets(str))
	{
		int i=1;
		str[0]=str[0]-32;
		while(str[i])
		{
			if(str[i-1]==' ')
				str[i]-=32;
			i++;
		}
		puts(str);
	}
	return 0;
}