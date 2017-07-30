#include<cstdio>
int n,k;
int F[111];
int num[111];
void init(){
	for(int i=1;i<=n;i++){
		F[i]=i;num[i]=0;
	}
}
void Found(int x){
	while(x!=F[x]){
		x=F[x];
		num[x]++;
	}
}
void Union(int x,int y){
	F[y]=x;
}
int main(){
	while(~scanf("%d %d",&n,&k)){
		int x,y;
		init();
		for(int i=0;i<n-1;i++){
			scanf("%d %d",&x,&y);
			Union(x,y);
		}
		for(int i=1;i<=n;i++){
			Found(i);
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(num[i]==k)
				cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}