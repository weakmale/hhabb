#include<cstdio>
int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m) != EOF){
	if(m < n / 2){
		int a = n;
		int num = 0;
		while(m < n / 2) n--,num++;
		if(num == 1) printf("-1\n");
		else printf("%d\n", m - ((a / 2 + 1) - num));
		continue;
	}
	if(n == 1) printf("-1\n");
	else if(n == 2) printf("%d\n",m);
	else if(n == 3) printf("%d\n",m - 2);
	else if(n == 4) printf("%d\n",(m - 3) >= 0 ? (m - 3) : 0);
	else printf("%d\n",(m - n / 2));
    }
	return 0;
}