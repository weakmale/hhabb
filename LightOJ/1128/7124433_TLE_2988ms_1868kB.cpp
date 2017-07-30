#include <cstdio>
#include <cstring>
const int MAXN=1e5+10;
int F[MAXN];
int id[MAXN];
int main(){
    int T; scanf("%d",&T);
    int kcase=1;
    while(T--){
        int n,m; scanf("%d %d",&n,&m);
        F[0]=0;id[0]=1;
        for(int i=1;i<n;i++)
            scanf("%d %d",&F[i],&id[i]);
        printf("Case %d:\n",kcase++);
        while(m--){
            int a,b; scanf("%d %d",&a,&b);
            while(id[a]>b&&F[a]!=a){
                int i=F[a];
                if(id[i]>=b)
                    a=F[a];
                else
                    break;
//                printf("%d~~~%d\n",a,id[a]);
            }
            printf("%d\n",a);
        }
    }
    return 0;
}
