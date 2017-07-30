#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int X;
int sum[300];
int a[300];
int need[300];
int main(){
		scanf("%d%d",&n,&X);
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
			int k=1;
			if(X>sum[i-1])
				need[j++]=a[i];
			while(X-a[i]<0){
				i--;k=0;
			}
			X=X-a[i];
			if(k)
				i--;
				
		}
		printf("%d\n",j);
		int t=0;
		for(int l=j-1;l>=0;l--){
			if(t++)
				printf(" ");
			printf("%d",need[l]);
		}
		printf("\n");
	return 0;
}