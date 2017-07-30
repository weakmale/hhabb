#include<cstdio>
const int MAXX=33333;
int n,m;
int F[MAXX];
int sum;
int num[MAXX];
void init(){
	for(int i=0;i<n;i++){
			F[i]=i;
			num[i]=1;
	}
}
int Found(int a){
	int r=a;
	while(r!=F[r]){
		r=F[r];
	}
	int i=a;
	while(i!=r){
		i=F[i];F[i]=r;
	}
	return r;
}
void Union(int a,int b){
	int x=Found(a);
	int y=Found(b);
	if(x!=y){
		F[y]=x;
		num[x]=num[x]+num[y];
	}
}
int main(){
	while(~scanf("%d %d",&n,&m),n||m){
		init();
		sum=1;
		int s;int y;int x;
		for(int i=0;i<m;i++){
			scanf("%d",&s);scanf("%d",&x);
			for(int j=0;j<s-1;j++){
				scanf("%d",&y);
				Union(x,y);
				x=y;
			}
		}
		printf("%d\n",num[Found(0)]);
	}
	return 0;
}