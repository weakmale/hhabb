#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
using namespace std;
const int MAXX=100000+10;
int n;
int m;
struct node
{
    int from;
    int to;
    int next;
}edge[MAXX];
int head[MAXX];
int len;
int du[MAXX];
int que[MAXX];
void init(){
    memset(du,0,sizeof(du));
    memset(head,-1,sizeof(head));
    len=0;
}
void join(int u,int v){
    edge[len].from=u;
    edge[len].to=v;
    edge[len].next=head[u];
    head[u]=len++;
}
void tupo()
{
    priority_queue < int, vector<int>, less<int> > Q;
    for(int i=1;i<=n;i++)
        if(du[i]==0)
            Q.push(i);
    int j=1;
    while(!Q.empty()){
        int t=Q.top(); Q.pop();
        que[j++]=t; du[t]=-1;
        for(int i=head[t];i!=-1;i=edge[i].next){
            int u=edge[i].to;
            du[u]--;
            if(du[u]==0)
                Q.push(u);
        }
    }
}
int main(){
	int T; scanf("%d",&T);
	while(T--)
    {   init();
        scanf("%d %d",&n,&m);
        int a;int b;
        for(int i=1;i<=m;i++){
            scanf("%d %d",&a,&b);
            join(a,b); du[b]++;
        }
        tupo();int minn=n+1; int sum=0;
        for(int i=1;i<=n;i++)
        {
            minn=min(minn,que[i]);
            sum+=minn;

        }
        printf("%d\n",sum);
    }
	return 0;
}