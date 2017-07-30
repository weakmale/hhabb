#include<cstdio>
int n,m;
int num[1000];
int F[1001];
void init(){
	for(int i=1;i<=n;i++){
		num[i]=0;F[i]=i;
	}
}
int Found(int x){
	if(x==F[x]) return x;
	F[x]=Found(F[x]);
	return F[x];
}
void Union(int x,int y){
	int nx=Found(x);
	int ny=Found(y);
	if(nx!=ny)
		F[nx]=ny;
}
int main(){
	while(scanf("%d",&n),n){
		scanf("%d",&m);
		int x,y;
		init();
		for(int i=0;i<m;i++){
			scanf("%d %d",&x,&y);
			Union(x,y);
			num[x]++;num[y]++;
		}
		bool k=true;
		int l=0;
		for(int i=1;i<=n;i++){
			if(F[i]==i)
				l++;
		}
		if(l>1)
			k=false;
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