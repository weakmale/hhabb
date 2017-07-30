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
	bool x=true;
		for(int i=1;i<=m;i++){
			if(a[i]!=b[i]){
				k=false;
				break;
			}	
			else 
				if(a[i]>1)
					x=false;
		}
		if(k){
			if(x){
				printf("Possible\n");
				for(int i=0;i<n;i++)
					printf("%d ",t[i]);
				printf("\n");
			}
			else
				printf("Ambiguity\n");
		}
		else
				printf("Impossible\n");
	return 0;
}