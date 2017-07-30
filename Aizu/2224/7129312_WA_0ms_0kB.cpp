#include "cstdio"
#include "algorithm"
#include "cmath"
using namespace std;
const int MAXN=10000+10;
int  n,m;
struct node{
    int a,b; double vi;
}edge[MAXN];
double x[MAXN];
double y[MAXN];
int F[MAXN];
int Found(int x){
    if(F[x]==x) return x;
    return F[x]=Found(F[x]);
}
bool Union(int x,int y){
    int xn=Found(x);
    int yn=Found(y);
    if(xn!=yn){
        F[yn]=xn;
        return true;
    }
    return false;
    
}
double dis(double x1,double y1,double x2,double y2){
    return sqrt(pow(x1-x2,2.0)+pow(y1-y2,2.0));
}
bool cmp(node a,node b){
    return a.vi>b.vi;
}
int main(){
    scanf("%d %d",&n,&m);
    double sum=0;
    for(int i=1;i<=n;i++){
        scanf("%lf %lf",&x[i],&y[i]);
    }
    for(int i=1;i<=m;i++){
        int a,b; scanf("%d %d",&a,&b);
        edge[i].a=a; edge[i].b=b;
        edge[i].vi=dis(x[a],y[a],x[b],y[b]);
        sum+=edge[i].vi;
    }
    for(int i=1;i<=n;i++)
        F[i]=i;
    sort(edge+1,edge+1+m,cmp);
    for(int i=1;i<=m;i++){
        if(Union(edge[i].a,edge[i].b)){
            sum-=edge[i].vi;
        }
    }
    printf("%.3lf\n",sum);
    return 0;
}
