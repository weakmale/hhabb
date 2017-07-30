#include "cstdio"
#include "iostream"
#include "algorithm"
#include "vector"
#include "queue"
using namespace std;
typedef long long  LL;
int a[100010];
int b[100010];
int num[100010];
struct node{
    LL num; int i;
    friend bool operator<(node a,node b){
        return a.num>b.num;
    }
};
priority_queue<node>Q;

int main(){
    int n; scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int i=1;i<=n;i++) scanf("%d",b+i);
    sort(a+1,a+1+n); sort(b+1,b+1+n);
    for(int i=1;i<=n;i++) Q.push({a[i]+b[1],1});
    for(int i=1;i<=n;i++){
        printf("%lld\n",Q.top().num);
        if(Q.top().i<n){
            Q.push({ Q.top().num-b[Q.top().i] + b[Q.top().i+1],Q.top().i+1});
        }
        Q.pop();
    }
    return 0;
}
