#include "cstdio"
using namespace std;
int F[30010];
int R[30010];
int K;
int Found(int x){
    if(F[x]==x){
        K=x;
        return x;
    }
    int t=F[x];
    F[x]=Found(t);
    if(t!=K)
        R[x]=R[x]+R[t];
    return F[x];
}
int main(){
    int Q; scanf("%d",&Q);
    for(int i=1;i<=30009;i++) F[i]=i;
    while(Q--){
        char s[2];int a,b;
        scanf("%s",s);
        if(s[0]=='C'){
            scanf("%d",&a);
            
            int na=Found(a);
//            printf("%d %d\n",a,na);
            if(na!=a)
                printf("%d\n",R[na]-R[a]);
            else
                printf("%d\n",R[na]);
        }
        else{
            scanf("%d %d",&a,&b);
            int na=Found(a),nb=Found(b);
            if(na!=nb){
                F[nb]=na;
                int t=R[nb];
                R[nb]=R[na]+1;
//                printf("%d",R[na]+1);
                R[na]=R[na]+t+1;
            }
//            printf("%d %d %d %d~~\n",a,R[a],na,R[na]);
//            printf("%d %d %d %d!!\n",b,R[b],nb,R[nb]);
        }
    }
    return 0;
}