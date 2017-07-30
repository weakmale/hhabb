#include<cstdio>
int main()
{
	int n; scanf("%d",&n);getchar();
	while(n--)
	{
		int i=1,l=0;
		char a[100];
		gets(a);
		if( (a[0]<65 || (a[0]>90&&a[0]<97) || a[0]>122) &&(a[0]!=95))
			l=1;
		while(a[i])
		{
			if(l)
				break;
			if( ( a[i]<48 || (a[i]>57&&a[i]<65) || (a[i]>90&&a[i]<97) || a[i]>122) && (a[i]!=95))
				l=1;
			if(i>50)
				l=1;
			i++;
		}
		if(l)
			printf("no\n");
		else
			printf("yes\n");
	}
	return 0;
} 