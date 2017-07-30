#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
struct node{
    int from,to;
    double vi;
}edge[210*210];
double x[210],y[210];
int F[210];
int Found(int x){ return x==F[x]?x:F[x]=Found(F[x]); }
double dis(double x1,double y1,double x2,double y2){ return sqrt(pow(x1-x2,2)+pow(y1-y2,2));}
bool cmp(node a,node b){ return a.vi<b.vi; }
bool Union(int x,int y){
    int nx=Found(x),ny=Found(y);
    if(nx!=ny){ F[ny]=nx; return true; }
    return false;
}
int main(){
    int n;int kcase=1;
    while(scanf("%d",&n),n){
        for(int i=1;i<=n;i++)
            scanf("%lf %lf",&x[i],&y[i]),F[i]=i;
        int t=0;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
              edge[++t].from=i,edge[t].to=j,edge[t].vi=dis(x[i],y[i],x[j],y[j]);
        sort(edge+1,edge+1+t,cmp);
        double maxx=0;
        for(int i=1;i<=t;i++){
            if(Union(edge[i].from,edge[i].to)){
                if(Found(1)==Found(2)){
                    maxx=edge[i].vi;
                    break;
                }
            }
        }
        printf("Scenario #%d\n",kcase++);
        printf("Frog Distance = %.3lf\n\n",maxx);
    }
    return 0;
}
