#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<functional>
using namespace std;
const int MAXX=10005;
int n,m;
int du[MAXX];
struct node{
	int to;
	int next;
};
node ega[MAXX*2];
int head[MAXX];
int l;
//int F[MAXX];
//bool K;
//int T[MAXX];
int many[MAXX];
int sum;
int ans;
void init(){
//	memset(T,0,sizeof(T));
//	K=true;//		F[i]=i; 

	
}
void join(int a,int b){

}
//int Found(int x){
//	if(F[x]==x) return x;
//	F[x]=Found(F[x]);
//	return F[x];
//}
//void Union(int x,int y){
//	int nx=Found(x);
//	int ny=Found(y);
//	if(nx!=ny){
//		F[ny]=nx;
//	}
//	else 
//		K=false;
//}
void topu()
{
    int i,j,l,v;
    queue<int>Q;
    for(i=1; i<=n; i++)
        if(du[i]==0)
            Q.push(i);
    while(!Q.empty())
    {
        v=Q.front();
        sum+=many[v];
        Q.pop();
        ans++; 
        for(l=head[v]; l!=-1; l=ega[l].next)
        {
            if(--du[ega[l].to]==0)
            {
                Q.push(ega[l].to);
                many[ega[l].to]=many[v]+1;
            }
        }

    }
}
int main(){
	while(scanf("%d %d",&n,&m)!=EOF){
		l=0;
		memset( du,0,sizeof(du) );
		memset( head,-1,sizeof(head));	
		for(int i=1;i<=n;i++){
			many[i]=888;
		}
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			ega[l].to=a;
			ega[l].next=head[b];
			head[b]=l++;
			du[a]++;
		}
		ans=0;
		sum=0;
		topu();
		if(ans!=n)
			printf("-1\n");
		else
			printf("%d\n",sum);
	}
	return 0;
}