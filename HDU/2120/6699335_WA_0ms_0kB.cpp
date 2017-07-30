#include<cstdio>
int n,m;
int F[1001];
int l;
int d;
bool num[1001];
void init(){
	for(int i=0;i<=1000;i++){
		F[i]=i;num[i]=false;
	}
	d=0;l=0;
}
int Found(int x){
	if(F[x]==x) return x;
	F[x]=Found(F[x]);
	return F[x];
}
void Union(int x,int y){
	int nx=Found(x);
	int ny=Found(y);
	l++;
	if(nx!=ny){
		F[ny]=F[nx];	
	}
}
int main(){
	while(scanf("%d %d",&n,&m)!=EOF){
		int x,y;
		init();
		for(int i=0;i<m;i++ ){
			scanf("%d %d",&x,&y);
			num[x]=true;
			num[y]=true;
			Union(x,y);
		}
		for(int i=0;i<=1000;i++)
			if(num[i])
				d++;
		printf("%d\n",l+1-d);
	}
	return 0;
}