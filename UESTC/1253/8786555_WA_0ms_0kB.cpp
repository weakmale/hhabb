#include<cstdio>
int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m) != EOF){
	if(n == 1) printf("-1\n");
	else if(n == 2) printf("%d\n",m - 1);
	else if(n == 3 || n == 4) printf("%d\n",m - 3 >= 0 ? m - 3 : -1);
	else printf("%d\n",(m - n / 2) >= 0 ? (m - n / 2) : -1);
    }
	return 0;
}