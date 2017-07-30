#include<cstdio>
int main()
{
	int y,m,d;
	while(scanf("%d/%d/%d",&y,&m,&d)!=EOF)
	{
		int sum=0;
		if( ( (y%4==0&&y%100!=0) || (y%400==0) ) && (m>2) )
		{
				sum+=29;
		}
		else if(m>2)
			sum+=28;
		while(--m)
		{
			if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
				sum+=31;
			if(m==4||m==6||m==9||m==11)
				sum+=30;
		}sum+=d;
		printf("%d\n",sum);
	}
	return 0;
 } 