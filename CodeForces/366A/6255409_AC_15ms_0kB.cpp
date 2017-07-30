#include<cstdio>
int main()
{
	int n; 
	while(scanf("%d",&n)!=EOF){
		int a1[4],a2[4],b1[4],b2[4],t=1;
		for(int j=0;j<4;j++)
			scanf("%d%d%d%d",&a1[j],&a2[j],&b1[j],&b2[j]);
		for(int j=0;j<4;j++){
			if(a1[j]>a2[j]) a1[j]=a2[j];
			if(b1[j]>b2[j]) b1[j]=b2[j];
			if(a1[j]+b1[j]<=n){
				printf("%d %d %d\n",j+1,a1[j],n-a1[j]);
				t=0; break;
			}
		}
		if(t) printf("-1\n");
	}
	return 0;
}
