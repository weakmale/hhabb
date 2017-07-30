#include<cstdio>
int n,m;
int F[1111];
void init(){
	for(int i=1;i<=n;i++)
		F[i]=i;
}
int Found(int x){
	if(x==F[x])	return x;
	F[x]=Found(F[x]);
	return F[x];
}
void Union(int x,int y){
	
	int nx=Found(x);
	int ny=Found(y);
	if(nx!=ny){
		F[ny]=nx;
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		init();
		int  table=0;
		int a,b;
		for(int i=0;i<m;i++){
			scanf("%d %d",&a,&b);
			Union(a,b);
		}
		for(int i=1;i<=n;i++){
			if(F[i]==i)
				table++;
		}
		printf("%d\n",table);
	}
	return 0;
}