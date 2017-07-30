#include<cstdio>
int n,m;
int num[1000];
void init(){
	for(int i=1;i<=n;i++)
		num[i]=0;
}
int main(){
	while(scanf("%d",&n),n){
		scanf("%d",&m);
		int x,y;
		init();
		for(int i=0;i<m;i++){
			scanf("%d %d",&x,&y);
			num[x]++;num[y]++;
		}
		int k=true;
		for(int i=1;i<=n;i++){
			if(num[i]%2==1)
				k=false;
		}
		if(k)
			printf("%d\n",k);
		else
			printf("%d\n",k);
		}
	return 0;
}