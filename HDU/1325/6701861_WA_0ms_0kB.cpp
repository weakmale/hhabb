#include<cstdio>
int x,y;
const int MAXX=100010;
int F[MAXX];
bool k;
int num[MAXX];
void init(){
	for(int i=1;i<=MAXX-1;i++){
		F[i]=i;num[i]=0;
	}
	k=true;
}
void Union(int x,int y){
	if(F[y]==y){
		F[y]=x;num[x]=1;
	}
	else
		k=false;
}
int main(){
	int t=1;
	while(scanf("%d %d",&x,&y)){
		if(x<0&&y<0)
			break;
		if(x==0&&y==0){
			printf("Case %d is a tree.\n",t++);
			continue;
		}
		init();
		Union(x,y);
		while(true){
			scanf("%d %d",&x,&y);
			if(x==0&&y==0)
				break;
			Union(x,y);
		}
		int t=0;
		for(int i=1;i<=MAXX-1;i++){
			if(num[i]&&F[i]==i)
				t++;
		}
		if(t>1)
			k=false;
		if(k)
			printf("Case %d is a tree.\n",t++);
		else
			printf("Case %d is not a tree.\n",t++);
	}
	return 0;
}