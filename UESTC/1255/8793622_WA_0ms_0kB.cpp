#include "cstdio"
#include "queue"
#include "algorithm"
using namespace std;
priority_queue<int,vector<int>,greater<int>>Q;
int F[1000010];
int main(){
    int n,m; scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++) Q.push(0);
    for(int i=1;i<=n;i++) scanf("%d",&F[i]);
    sort(F+1, F+1+n);
    int sum=0,t=0;
    for(int i=n;i>=1;i--){
        int k=Q.top();Q.pop();
        if(k+F[i]<=t)
            Q.push(k+F[i]);
        else{
            sum = sum+(k+F[i]-t);
            t=k+F[i];
            Q.push(k+F[i]);
        }
    }
    printf("%d\n",sum);
    return 0;
}