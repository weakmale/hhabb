#include "cstdio"
#include "cstring"
#include "algorithm"
using namespace std;
int vis[25];
int id[25];
int dp[10000];
int dis[10000];
int t;
int judge(int vist[]){
    int sum=0;
    for(int i=1;i<=9;i++){
        if(vist[i]&&vist[i+3]&&vist[i+12+(i-1)/3]&&vist[i+13+(i-1)/3])
            sum++;
    }
    return sum;
}
int status(int x)
{
    int sum=0,i;
    int vist[26];
    for(i=0;i<=24;i++)vist[i]=0;
    for(i=1;i<=t;i++)
    {
        if(x&(1<<(i-1)))
        {
            vist[id[i-1]]=1;
        }
    }
    for(i=1;i<=24;i++)
    {
        if(vis[i])vist[i]=1;
    }
    sum=judge(vist);
    return sum;
}
int DFS(int x)
{
    if(dis[x]!=-1)return dis[x];
    int ans=0;
    for(int i=1;i<=t;i++)
    {
        if(!(x&(1<<(i-1))))
        {
            int y;
            y=x+(1<<(i-1));
            int ss;
            ss=DFS(y);
            ans=max(9-dp[x]-ss,ans);
        }
    }
    dis[x]=ans;
    return ans;
}
int main(){
    int T; scanf("%d",&T); int kcase=1;
    while(T--){
        int ans1=0,ans2=0;int s=0;
        memset(vis, false, sizeof(vis));
        memset(dis, -1, sizeof(dis));
        
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
//        printf("%d %d %d %d\n",ans1,ans2,ans,make);
        printf("Case #%d: ",kcase++);
        if(n&1){
            if(ans2+make>ans1+ans-make) printf("Jerry404\n");
            else printf("Tom200\n");
        }
        else{
            if(ans1+make<ans2+ans-make) printf("Jerry404\n");
            else printf("Tom200\n");
        }
    }
    return 0;
}