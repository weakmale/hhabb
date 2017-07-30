#include<cstdio>
int a[100011]={0};
int b[100011]={0};
int t[100011]={0};
struct node{
	int I;
	int num;
}p[100011];
int main(){
	int m,n;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i].num);
		p[p[i].num].I=i;
		a[p[i].num]++;
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&t[i]);b[t[i]]++;
	}
	bool k=true;
	bool x=true;
	for(int i=1;i<=m;i++){
		if(a[i]!=b[i]){
			k=false;
			break;
		}	
		else {
			if(a[i]>1)
				x=false;
		}
	}
	if(n==m){
		if(k){
			if(x){
				printf("Possible\n");
				for(int i=1;i<=m;i++)
					printf("%d ",p[t[i]].I);
				printf("\n");
			}
			else
				printf("Ambiguity\n");
		}
		else
				printf("Impossible\n");
		}
	else
		printf("Impossible\n");
	return 0;
}