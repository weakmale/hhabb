#include<cstdio>
int main()
{
	int n;scanf("%d",&n);
	while(n--){
		int m;scanf("%d",&m);
		int a[41];a[1]=1;a[2]=1;a[3]=2;
		for(int i=4;i<41;i++)
			a[i]=a[i-1]+a[i-2];
		printf("%d\n",a[m]);
	}
	return 0;
}
