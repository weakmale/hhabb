#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<functional>
using namespace std;
const int MAXX=122;
int n,m;
int du[MAXX];
struct node{
	int to;
	int next;
};
node ega[MAXX*MAXX];
int head[MAXX];
int l=0;
void init(){
	memset( head,-1,sizeof(head));
	l=0;
	memset( du,0,sizeof(du) );
}
void join(int a,int b){
	ega[l].to=b;
	ega[l].next=head[a];
	head[a]=l++;
}
void topu(){
	priority_queue<int  >Q;//, vector<int> , greater<int>
	for(int i=1;i<=n;i++)
		if(du[i]==0)
			Q.push(i);
	int sign=1;
	for(int i=1;i<=n;i++){
		int top=Q.top();
		Q.pop();
		du[top]=-1;
		if(sign)
            printf("%d",top);
        else
            printf(" %d",top);
        sign=0;
        for(int i=head[top];i!=-1;i=ega[i].next)
        {
        	du[ega[i].to]--;
        	if(du[ega[i].to]==0)
        		Q.push(ega[i].to);
		}
	}
	printf("\n");
}
int main(){
	while(scanf("%d",&n)!=EOF){
		init();
		for(int i=1;i<=n;i++){
			int a;
			while(scanf("%d",&a),a){
				du[a]++; join(i,a);
			}
		}
		topu();
	}
	return 0;
}
