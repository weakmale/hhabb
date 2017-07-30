#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
int Map[1010][1010];
struct node{
    int a,b,c;
}dian[1010*1010*4];
bool cmp(node a,node b){
    return a.c<b.c;
}
int xi[4]={1,-1,0,0};
int yi[4]={0,0,1,-1};
int F[1010*1010+10];
void init(int n){
    for(int i=1;i<=n;i++)
        F[i]=i;
}
int Found(int x){
    if(F[x]==x)return F[x];
    F[x]=Found(F[x]);
    return F[x];
}
bool  Union(int x,int y){
    int nx=Found(x);
    int ny=Found(y);
    if(nx!=ny){
        F[ny]=nx; return true;
    }
    return false;
}
int main(){
	int T;scanf("%d",&T); int w=1;
	while(T--){
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
                scanf("%d",&Map[i][j]);
        }
        init(n*m);
        int t=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
               for(int k=0;k<4;k++){
                    int nx=i+xi[k];
                    int ny=j+yi[k];
                    if(nx>=1&&ny>=1&&nx<=n&&ny<=m){
                        int a=m*(i-1)+j; int b=m*(nx-1)+ny;
                        int c=abs(Map[i][j]-Map[nx][ny]);
                        dian[++t].a=a; dian[t].b=b; dian[t].c=c;
                    }
               }
            }
        }
        sort(dian+1,dian+1+t,cmp);
        int sum=0;
        for(int i=1;i<=t;i++){
            if( Union(dian[i].a,dian[i].b) )
                sum+=dian[i].c;
        }
        printf("Case #%d:\n",w++);
        printf("%d\n",sum);
	}
	return 0;
}
