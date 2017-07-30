#include<cstdio>
#include<queue>
using namespace std;
struct node{
    int l;
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
            scanf("%d",&a.l);
            cnt.push(a);
        }
        if (n==1) {
            printf("%d\n",a.l);
            continue;
        }
        int  sum=0;
        
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
        printf("%d\n",sum);
    }
    return 0;
}