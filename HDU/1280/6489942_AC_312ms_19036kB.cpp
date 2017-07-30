#include<cstdio>
#include<algorithm>
using namespace std;
int b[9000000];
int main(){
	int m,n;
	int a[3010];
	int k=0;
	int i;
	int j;
	while(~scanf("%d%d",&n,&m)){
		for( i=0;i<n;i++)
			scanf("%d",&a[i]);
        for(i=0;i<n-1;i++){
            for( j=i+1;j<n;j++){   
                b[k]=a[i]+a[j];  
                k++;  
            }  
        }  
		sort(b,b+k);
		printf("%d",b[k-1]);
		for(i=k-2;i>k-m-1;i--){
			printf(" %d",b[i]);
		}
		printf("\n");
	}
	return 0;
}