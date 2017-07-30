#include "cstdio"
#include "algorithm"
using namespace std;
int n,m;
int F[510],R[510],a[2010],b[2010];
char c[2010];
int Found(int x){
    if(F[x]==x) return x;
    int t=F[x];
    F[x]=Found(t);
    R[x]=(R[x]+R[t])%3;
    return F[x];
}

int main(){
    while(~scanf("%d %d",&n,&m)){
        for(int i=1;i<=m;i++) scanf("%d%c%d",a+i,c+i,b+i);
        int ans=0,t=0,maxx=0;
        for(int i=0;i<n;i++){
            for(int i=0;i<=n;i++) F[i]=i,R[i]=0;
            int ff=-1;
            for(int j=1;j<=m;j++){
                if(a[j]==i||b[j]==i) continue;
                int k=0;
                if(c[j]=='>') k=1;
                else if(c[j]=='<') k=2;
                
                int na=Found(a[j]),nb=Found(b[j]);
                
                if(na!=nb)
                    F[nb]=na,R[nb]=(R[a[j]]-R[b[j]]-k+3)%3;
                else{
//                    printf("%d %d %d %d\n",j,k,R[a[j]],R[b[j]]);
                    if((R[a[j]]-R[b[j]]+3)%3!=k){
                        ff=j;break;
                    }
                }
            }
//            printf("%d %d\n",ff,i);
            if(ff==-1){
                ans=i;t++;
            }
            else
                maxx=max(maxx,ff);
        }
//        printf("%d\n",t);
        if(t>1)puts("Can not determine");
        else if(t==0) puts("Impossible");
        else printf("Player %d can be determined to be the judge after %d lines\n",ans,maxx);
    }
}