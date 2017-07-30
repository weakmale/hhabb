#include "cstdio"
#include "cstring"
#include "algorithm"
using namespace std;
bool vis[25];
int id[25];
int dp[10000];
int dis[10000];
int t;
int judge(bool vist[]){
    int sum=0;
    for(int i=1;i<=9;i++){
        if(vist[i]&&vis[i+3]&&vis[i+12+(i-1)/3]&&vis[i+13+(i-1)/3])
            sum++;
    }
    return sum;
}
int status(int x){
    bool vist[25];
    memset(vist,false,sizeof(vist));
    for(int i=1;i<=t;i++){
        if(x&(1<<(i-1))){
            vist[i-1]=true;
        }
    }
    for(int i=1;i<=24;i++)
        if(vis[i]) vist[i]=true;
    return judge(vist);
}
int DFS(int x){
    int ans=0;
    if(dis[x]!=-1) return dis[x];
    for(int i=1;i<=t;i++){
        if(!(x&(1<<(i-1)))){
            int y=x+(1<<(i-1));
//            printf("%d %d %d\n",x,y,i);
            int ss=DFS(y);
            ans=max(9-dp[x]-ss,ans);
        }
    }
//    printf("%d\n",x);
    dis[x]=ans;
    return ans;
}
int main(){
    int T; scanf("%d",&T); int kcase=1;
    while(T--){
        int ans1=0,ans2=0;int s=0;
        memset(vis, false, sizeof(vis));
        memset(dis, -1, sizeof(dis));
//        printf("Case #%d: ",kcase++);
        int n; scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int a,b; scanf("%d %d",&a,&b);
            if(a>b) swap(a, b);
            if(b-a==4) t=12+a;
            else t=a-a/4;
            vis[t]=true;
            if(i&1)
                ans1+=(judge(vis)-s);
            else
                ans2+=(judge(vis)-s);
            s=judge(vis);
//            printf("~~~%d %d\n",ans1,ans2);
        }
        t=0;
        for(int i=1;i<=24;i++) if(!vis[i]) id[t++]=i;
        for(int i=0;i<(1<<t);i++){
            dp[i]=status(i);
        }
        int ans=9-s;
        int make=DFS(0);
//        printf("%d %d %d %d\n",ans,ans1,ans2,make);
        if(n&1){
            if(ans2+make>ans1+ans-make) printf("Jerry404~~\n");
            else printf("Tom200\n");
        }
        else{
            if(ans1+make<ans2+ans-make) printf("Jerry404\n");
            else printf("Tom200\n");
        }
    }
    return 0;
}