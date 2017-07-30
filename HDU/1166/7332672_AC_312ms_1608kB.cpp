#include "cstdio"
#include "cstring"
using namespace std;
int sum[50010];
int lowbet(int x){
    return x&-x;
}
int Sum(int x){
    int m=0;
    while(x){
        m+=sum[x];
        x-=lowbet(x);
    }
    return m;
}
void add(int x,int c,int n){
    while(x<=n){
        sum[x]+=c;
        x+=lowbet(x);
    }
    
}
int main(){
    int T; scanf("%d",&T); int kcase=1;
    while(T--){
        memset(sum,0,sizeof(sum));
        int n; scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int a; scanf("%d",&a);
            add(i,a,n);
        }
        printf("Case %d:\n",kcase++);
        char s[10];
        scanf("%s",s);
        while(s[0]!='E'){
            int a,b; scanf("%d %d",&a,&b);
            if(s[0]=='Q')
                printf("%d\n",Sum(b)-Sum(a-1));
            else if(s[0]=='A'){
                add(a,b,n);
            }
            else
                add(a,-b,n);
            scanf("%s",s);
        }
    }
    return 0;
}
