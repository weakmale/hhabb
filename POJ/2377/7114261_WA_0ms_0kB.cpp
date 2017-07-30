#include "cstdio"
#include "algorithm"
using namespace std;
struct node{
    int a,b,v;
}edge[20010];
bool cmp(node a,node b){
    return a.v>b.v;
}
int F[1010];
int  Find(int x){
    if(x==F[x])return x;
    return F[x]=Find(F[x]);
}
bool Union(int x,int y){
    int nx=Find(x);
    int ny=Find(y);
    if(nx!=ny){
        F[ny]=nx;
        return true;
    }
    return false;
}
int main(){
    int n,m;
    while(~scanf("%d %d",&n,&m)){
        for(int i=1;i<=n;i++)
            F[i]=i;
        for(int i=1;i<=m;i++)
            scanf("%d %d %d",&edge[i].a,&edge[i].b,&edge[i].v);
        sort(edge+1,edge+1+m,cmp);
        int sum=0;
        for(int i=1;i<=m;i++){
//            printf("%d\n",edge[i].v);
            if(Union(edge[i].a,edge[i].b)){
                sum+=edge[i].v;
            }
        }
        int k=0;
        for(int i=1;i<=n;i++){
            if(F[i]==i)
                k++;
        }
        if(k>1)
            printf("1\n");
        else
            printf("%d\n",sum);
    }
    return 0;
}