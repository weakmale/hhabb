#include<cstdio>
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		a=a+2; b=b+2;
		for(int i=1;i<=b;i++){
			if(i==1||i==b)
			{
				printf("+");
				for(int j=2;j<a;j++)
					printf("-");
				printf("+");
			}
			else
			{
				for(int j=1;j<=a;j++){
					if(j==1||j==a){
						printf("|");
					}
					else{
						printf(" ");
					}
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}