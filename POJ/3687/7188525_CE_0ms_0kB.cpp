#include "cstdio"
#include "vector"
#include "algorithm"
#include "queue"
using namespace std;
struct node{
    int from,to,next;
}edge[40010];
int head[210];
int ln;
int du[210];
void init(){
    memset(du,0,sizeof(du));
    ln=0; memset(head, -1, sizeof(head));
}
void join(int u,int v){
    edge[ln].from=u;
    edge[ln].to=v;
    edge[ln].next=head[u];
    head[u]=ln++;
}
int id[210];
void tuopo(int n){
    
	priority_queue<int , vector<int>,greater<int> >Q;
    int t=0;
    for(int i=1;i<=n;i++){
        if(du[i]==0)
            Q.push(i);
    }
    
    while(!Q.empty()){
        
        int u=Q.top();Q.pop();
        du[u]=-1;
        id[++t]=u;
        if(t>n){
            printf("-1\n"); return ;
        }
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].to;
            du[v]--;
            if(du[v]==0)
                Q.push(v);
            printf("%d\n",v);
        }
        
    }
    
    if(t!=n){
        printf("-1\n");
    }
    else{
        printf("%d",id[1]);
        for(int i=2;i<=t;i++)
            printf(" %d",id[i]);
        printf("\n");
    }
}
int main(){
    int T; scanf("%d",&T);
    while(T--){
        
        int n,m; init();
        
        scanf("%d %d",&n,&m);
        int k=1;
        while(m--){
            int a,b;
            scanf("%d %d",&a,&b);
            du[b]++;
            join(a,b);
            if(a==b)
                k=0;
        }
//        for(int i=head[3];i!=-1;i=edge[i].next)
//            printf("%d\n",edge[i].to);
//        if(k)
            tuopo(n);
//        else
//            printf("-1~~~\n");
    }
    return 0;
}