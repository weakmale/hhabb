#include<cstdio>
int a[1050];
void init(int n){
	for(int i=1;i<=n;i++)
		a[i]=i;
}
int Found(int t){
	int r=t;
	while(a[r]!=r)
		r=a[r];
	return r;
}
void Union(int p,int q){
	int x=Found(p);
	int y=Found(q);
	if(x!=y)
		a[x]=y;
}
int main(){
	int n,m;
	while(~scanf("%d",&n),n){
		scanf("%d",&m);
		init(n);
		int cnt=0;
		for(int i=1;i<=m;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			Union(x,y);
		}
		for(int i=1;i<=n;i++){
			if(a[i]==i)
				cnt++;
		}
		
		printf("%d\n",cnt-1);
	}
	return 0;
}