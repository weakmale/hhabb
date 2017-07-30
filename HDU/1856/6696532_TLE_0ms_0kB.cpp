#include<cstdio>
int n;
const int MAXX=10000111;
int F[MAXX];
int num[MAXX];
void init(){
	for(int i=1;i<=MAXX;i++){
		F[i]=i;
		num[i]=1;
	}
}
int Found(int x){
	if(x==F[x]) return x;
	F[x]=Found(F[x]);
	return F[x];
}
void Union(int x,int y){
	int xn=Found(x);
	int yn=Found(y);
	if(xn!=yn){
		F[yn]=F[xn];
		num[xn]+=num[yn];
	}
}
int main(){
	while(scanf("%d",&n)!=EOF){
		int x,y;
		init();
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&x,&y);
			Union(x,y);
		}
		int maxx=0;
		for(int i=1;i<=MAXX;i++)
			if(num[i]>maxx)
				maxx=num[i];
		printf("%d\n",maxx);
	}
	return 0;
}