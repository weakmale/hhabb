#include<cstdio>
int main(){
	int n;
	scanf("%d",&n);
	if(n%4==0)
		printf("%d\n",n/4-1);
	else
	{
		printf("%d\n",(n/2-1)/2);
	}
	return 0;
}