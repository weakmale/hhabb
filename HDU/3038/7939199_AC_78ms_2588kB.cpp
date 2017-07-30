#include "cstdio"
using namespace std;
int F[200010];
int num[200010];
int ans;
int Find(int x){
    if(F[x]!=x){
        int xf = F[x];
        F[x] = Find(F[x]);
        num[x]=num[x]+num[xf];
        return F[x];
    }
    return x;
}
void Unoin(int x,int y,int k){
    int nx = Find(x); int ny = Find(y);
    if(nx!=ny){
        F[ny] = nx;
        num[ny] = num[x] - num[y] + k;
    }
    else
        if(num[y]-num[x]!=k)
            ans++;
}
int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
        for(int i=1;i<=n;i++)
            num[i]=0,F[i]=i;
        ans = 0;
        while(m--){
            int a,b,c; scanf("%d %d %d",&a,&b,&c);
            a--;
            Unoin(a, b, c);
        }
        printf("%d\n",ans);
    }
    return 0;
}