#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
struct node{
	int from;
	int to;
	int vi;
	int next;
};
node ega[5001*2];
int head[5001];
int l;
int init(){
	memset(head,-1,sizeof(head));
	l=0;
}
void join(int u,int v,int w){
	ega[l].from=u;
	ega[l].to=v;
	ega[l].vi=w;
	ega[l].next=head[u];
	head[u]=l++;
}
int prim(int n) 
{
	int vis[105]={0},dis[105],ans=0;
	memset(dis,inf,sizeof(dis));//初始化为无穷大 
	dis[1]=0;//随意选定一个点开始 
	for(int i=1;i<=n;++i)//循环加入n个顶点 
	{
		int k=-1,tp=inf; 
		for(int j=1;j<=n;++j)
		//查找距离已连接的部分最近的顶点 
		{
			if(!vis[j]&&dis[j]<tp)
			{
				k=j;tp=dis[j];
			}
		}
		vis[k]=1;ans+=tp;//统计和标记 
		for(int j=head[k];j!=-1;j=ega[j].next){
			int v=ega[j].to;
			if(!vis[v]&&dis[v]>ega[j].vi){
				dis[v]=ega[j].vi;
			}
		}
//		for(int j=1;j<=n;++j)
//		//更新未选中的点和已经连接的部分之间的最短距离 
//		{
//			if(!vis[j]&&map[k][j]<dis[j])
//			{
//				dis[j]=map[k][j];
//			}
//		}
	}
	return ans;
}
int main()
{
    int n,m,a,b,c;
    while(scanf("%d",&n)&&n)
    {
    	init();
        m=n*(n-1)/2;//边的数量 
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            join(a,b,c);
            join(b,a,c);
        }
        printf("%d\n",prim(n));
    }
    return 0;
}