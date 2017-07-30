#include<cstdio>
#include<queue>
using namespace std;
struct node{
    long long l;
    bool friend operator < (node a,node b){
        return a.l>b.l;
    }
}a;
int main(){
    int n;
    node b;
    while(~scanf("%d",&n)){
        priority_queue<node> cnt;
        for(int i=0;i<n;i++){
            scanf("%lld",&a.l);
            cnt.push(a);
        }
        if (n==1) {
            printf("%lld\n",a.l);
            continue;
        }
        long long  sum=0;
        
        while(!cnt.empty()){
            a=cnt.top();
            cnt.pop();
            if(!cnt.empty()){
                b=cnt.top();
                cnt.pop();
                a.l=a.l+b.l;
                sum+=a.l;
                cnt.push(a);
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}