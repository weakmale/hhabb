#include<cstdio>
int n;
int d;
int F[100001];
int g[100001];
void init(){
	for(int i=0;i<n;i++){
		F[i]=i;
	}
}
int Found(int x){
	int r=x;
	while(r!=F[r])
		r=F[r];
	return r;
}
int ans(int x){
	int ans=0;
	while(x!=F[x]){
		ans++;
		x=F[x];
	}
	return ans;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&d);
		init();
		for(int i=0;i<n-1;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			if(x>y)
				F[x]=y;
			else
				F[y]=x;
		}
		int cnt=0;
		for(int i=0;i<n;i++){
			if(ans(i)>d&&Found(i)==0)
				cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}