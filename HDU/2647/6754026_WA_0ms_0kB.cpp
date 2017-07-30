#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<functional>
using namespace std;
const int MAXX=10002;
int n,m;
int du[MAXX];
struct node{
	int to;
	int next;
};
node ega[MAXX*2];
int head[MAXX];
int l=0;
int F[MAXX];
bool K;
void init(){
	K=true;
	for(int i=1;i<=n;i++)
		F[i]=i;
	memset( head,-1,sizeof(head));
	l=0;
	memset( du,0,sizeof(du) );
}
void join(int a,int b){
	ega[l].to=b;
	ega[l].next=head[a];
	head[a]=l++;
}
int Found(int x){
	if(F[x]==x) return x;
	F[x]=Found(F[x]);
	return F[x];
}
void Union(int x,int y){
	int nx=Found(x);
	int ny=Found(y);
	if(nx!=ny){
		F[ny]=nx;
	}
	else 
		K=false;
}
int T[MAXX];
void tuopu(){
	priority_queue<int , vector<int>,greater<int> >Q;
	int t=0;
	for(int i=1;i<=n;i++){
		if(du[i]==0){
			Q.push(i);
			T[t]++;
		}
	};t++;
	while(!Q.empty()){
		int top=Q.top(); Q.pop();
		du[top]=-1;
		for(int i=head[top];i!=-1;i=ega[i].next){
			du[ega[i].to]--;
			if(du[ega[i].to]==0){
				T[t]++; Q.push(ega[i].to);
			}
		}
		t++;
	}
	int sum=0;
	for(int i=0;i<t;i++){
		sum+=(888+i)*T[i];
	}
	printf("%d\n",sum);
}
int main(){
	while(scanf("%d %d",&n,&m)!=EOF){
		init();
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			if(K){
				Union(a,b);
				join(a,b);	du[b]++;
			}
		}
		if(K)
			tuopu();
		else
			printf("-1\n");
	}
	return 0;
}