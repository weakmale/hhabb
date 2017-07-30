#include<cstdio>
#include<queue>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXX=10000+10;
struct node{
	int from;
	int to;
	int len;
	int next;
};
int n;
node edge[MAXX*2];
int head[MAXX];
int l;
int maxn[MAXX];
int smaxn[MAXX];
int maxid[MAXX];
int smaxid[MAXX];
void init(){
	memset(head,-1,sizeof(head));
	l=0;
}
void join(int u,int v,int w){
	edge[l].from=u;
	edge[l].to=v;
	edge[l].len=w;
	edge[l].next=head[u];
	head[u]=l++;
}
void DFS1(int u,int p)
{
    maxn[u]=0;
    smaxn[u]=0;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==p)continue;//不能往上找父亲结点
        DFS1(v,u);
        if(smaxn[u]<maxn[v]+edge[i].len)
        {
            smaxn[u]=maxn[v]+edge[i].len;
            smaxid[u]=v;
            if(smaxn[u]>maxn[u])
            {
                swap(smaxn[u],maxn[u]);
                swap(smaxid[u],maxid[u]);
            }
        }
    }
}
void DFS2(int u,int p)
{
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==p)continue;
        if(v==maxid[u])
        {
            if(edge[i].len+smaxn[u]>smaxn[v])
            {

                smaxn[v]=edge[i].len+smaxn[u];
                smaxid[v]=u;
                if(smaxn[v]>maxn[v])
                {
                    swap(smaxn[v],maxn[v]);
                    swap(smaxid[v],maxid[v]);
                }
            }
        }
        else
        {
            if(edge[i].len+maxn[u]>smaxn[v])
            {
                smaxn[v]=edge[i].len+maxn[u];
                smaxid[v]=u;
                if(smaxn[v]>maxn[v])
                {
                    swap(smaxn[v],maxn[v]);
                    swap(maxid[v],smaxid[v]);
                }
            }
        }
        DFS2(v,u);
    }
}
int main(){
	while(scanf("%d",&n)){
		int a,b;   init();
		for(int i=2;i<=n;i++){
			scanf("%d%d",&a,&b);
			join(i,a,b);
			join(a,i,b);
		}
		DFS1(1,-1);
		DFS2(1,-1);
		for(int i=1;i<=n;i++)
			printf("%d\n",maxn[i]);
	}
	return 0;
}