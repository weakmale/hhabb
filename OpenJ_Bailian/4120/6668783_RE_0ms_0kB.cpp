#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int X;
int sum[300];
int a[300];
int need[300];
int main(){
	while(scanf("%d%d",&n,&X)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(i>1)
				sum[i]=sum[i-1]+a[i];
			else
				sum[i]=a[i];
		}
		int i=n;
		int j=0;
		while(X){
			if(X>sum[i-1])
				need[j++]=a[i];
			X=X-a[i];
			i--;
		}
		sort(need,need+j);
		printf("%d\n",j);
		for(int l=0;l<j;l++){
			if(l)
				printf(" ");
			printf("%d",need[l]);
		}
		printf("\n");
	}
	return 0;
}