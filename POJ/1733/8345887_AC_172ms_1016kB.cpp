#include "iostream"
#include "cstdio"
#include "map"
using namespace std;
map<int ,int>Map;
int a[5010];
int b[5010];
bool c[5010];
int F[5010];
int R[5010];
int Found(int x){
    if(x==F[x])
        return x;
    int t=F[x];
    F[x]=Found(F[x]);
    R[x]=(R[x]+R[t])%2;
    return F[x];
}
int main(){
    int n,m; scanf("%d %d",&n,&m);
    int t=1;
    for(int i=1;i<=m;i++){
        char s[10];
        scanf("%d %d %s",&a[i],&b[i],s);
        if(!Map[a[i]-1]) R[t]=0,F[t]=t,Map[a[i]-1]=t++;
        if(!Map[b[i]]) R[t]=0,F[t]=t,Map[b[i]]=t++;
        if(s[0]=='e') c[i]=true;
        else  c[i]=false;
    }
    int ans=0;
    for(int i=1;i<=m;i++){
        int x=Map[a[i]-1],y=Map[b[i]];
        
        int nx=Found(x),ny=Found(y);
        if(c[i]){
            if(nx!=ny){
                F[ny]=nx;
                R[ny]=(R[x]-R[y]+2)%2;
            }
            else if((R[y]-R[x]+2)%2!=0)
                break;
            ans++;
        }
        else{
            if(nx!=ny){
                F[ny]=nx;
                R[ny]=(R[x]-R[y]+1+2)%2;
            }
            else if((R[y]-R[x]+2)%2!=1)
                break;
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}