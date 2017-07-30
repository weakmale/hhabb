#include<cstdio>
int n;
int a[111];
int b[111];
int F[111];
void init(){
	for(int i=1;i<=n;i++)
		F[i]=i;
}
int  Found(int e){
	int r=e;
	while(r!=F[r])
		r=F[r];
	return r;
}
void Union(int p,int q){
	int x = Found(p);
	int y = Found(q);
	if(F[x]!=F[y])
		F[x]=y;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int cnt=0;
		scanf("%d",&n);
		for(int i=1;i<=n+1;i++)
			scanf("%d %d",&a[i],&b[i]);
		for(int i=1;i<=n+1;i++){
			init();
			for(int j=1;j<=n+1;j++){
				if(j!=i)
					Union(a[j],b[j]);
			}
			int k=0;
			for(int j=1;j<=n;j++){
				if(F[j]==j)
					k++;
			}
			if(k==1)
				cnt++;
			
		}
		for(int i=1;i<=n+1;i++){
			for(int j=i+1;j<=n+1;j++){
				init();
				for(int t=1;t<=n+1;t++){
					if(t==i||t==j)
						continue;
					Union(a[t],b[t]);
				}
				int k=0;
				for(int t=1;t<=n;t++){
					if(F[t]==t)
						k++;
					}
				if(k==1)
					cnt++;	
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}