#include "cstdio"
#include "algorithm"
#include "iostream"
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
        for(int i=1;i<=m;i++) cin>>a[i]>>c[i]>>b[i];
//        for(int i=1;i<=m;i++) cout<<a[i]<<c[i]<<b[i]<<endl;;
        int ans=0,t=0,maxx=0;
        for(int i=0;i<n;i++){
            for(int i=0;i<n;i++) F[i]=i,R[i]=0;
            int ff=-1;
            for(int j=1;j<=m;j++){
                if(a[j]==i||b[j]==i) continue;
                int u=a[j],v=b[j];
                int k=0;
                if(c[j]=='<') k=1;
                else if(c[j]=='>') k=2;
                int t1=Found(u);
                int t2=Found(v);
                if(t1==t2)
                {
                    if(R[v]!=(R[u]+k)%3)
                    {
                        ff=j;
                        break;
                    }
                }
                else
                {
                    F[t2]=t1;
                    R[t2]=R[u]-R[v]+k;
                    R[t2]=(R[t2]+3)%3;
                }
            }
//            printf("%d %d\n",ff,i);
            if(ff==-1)
                ans=i,t++;
            else
                maxx=max(maxx,ff);
        }
//        printf("%d\n",t);
        if(t>1)puts("Can not determine");
        else if(t==0) puts("Impossible");
        else printf("Player %d can be determined to be the judge after %d lines\n",ans,maxx);
    }
}
