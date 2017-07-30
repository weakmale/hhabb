#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXX=101;
struct node{
	int x;
	int y;
	int vi;
}ega[MAXX];
int n;
int m;
bool cmp(node a,node b){
	return a.vi<b.vi;
}
int F[MAXX];
void init(){
	for(int i=1;i<=m;i++)
		F[i]=i;
	memset(ega,0,sizeof(ega));
}
int Found(int x){
	if(x==F[x]) return x;
	F[x]=Found(F[x]);
	return F[x];
}
bool Union(int x,int y){
	int nx=Found(x);
	int ny=Found(y);
	if(nx!=ny){
		F[nx]=ny;
		return true;
	}
	else
		return false;
}
int main(){
	while(scanf("%d %d",&n,&m)!=EOF,n){
		init();
		for(int i=0;i<n;i++){
			scanf("%d %d %d",&ega[i].x,&ega[i].y,&ega[i].vi);
		}
		sort(ega,ega+n,cmp);
		int ans=0,cnt=0;
		for(int i=0;i<n;i++){
			if(Union(ega[i].x,ega[i].y)){
				ans+=ega[i].vi;cnt++;
			}
		}
		if(cnt==m-1){
			printf("%d\n",ans);
		}
		else{
			printf("?\n");
		}
	}
	return 0;
}