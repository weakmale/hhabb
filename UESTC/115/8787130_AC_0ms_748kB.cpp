#include<cstdio>
int main()
{
	int T,n,m;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		if(n & 1 && m & 1) printf("Aoiing will win.\n");
		else puts("Zhym will win.");
	}
	return 0;
}