#include<cstdio>
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)&&(a!=0||b!=0))
	{
		int h,j=0; h=a%b;
			h=h*100;
			for(int i=0;i<100;i++)
			{
				if( (h+i) % b==0 )
				{
					if(j)
						printf(" ");
					if(i<10)
						printf("0%d",i);
					else
						printf("%d",i);
					j=1; 
				}
			}
			printf("\n");
	}
	return 0;
 } 