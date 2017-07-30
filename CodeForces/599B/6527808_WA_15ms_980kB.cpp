#include<cstdio>
#include<algorithm>
using namespace std;
int a[100011]={0};
int b[100011]={0};
int t[100011]={0};
int main(){
	int m,n;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		
		scanf("%d",&t[i]);
		a[t[i]]++;
	}
	for(int i=0;i<m;i++){
		int l;
		scanf("%d",&l);b[l]++;
	}
	bool k=true;
	if(m!=n)
		printf("Impossible\n");
	else{
		for(int i=1;i<=n;i++){
			if(a[i]!=b[i]){
				printf("Impossible\n");
				k=false;
				break;
			}	
			else{
				if(a[i]>1){
					printf("Ambiguity\n");
					k=false;
					break;}
			}
		}
		if(k){
			printf("Possible\n");
			for(int i=0;i<n;i++)
				printf("%d ",t[i]);
			printf("\n");
		}
	}
	return 0;
}