#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
int n,m;
int F[1010];
int vis[1010];
void init(){
    for(int i=1;i<=n;i++)
        F[i]=i;
    memset(vis,0,sizeof(vis));
}
int Found(int x){
    if(x==F[x]) return F[x];
    F[x]=Found(F[x]);
    return F[x];
}
void Union(int x,int y){
    int nx=Found(x);
    int ny=Found(y);
    if(nx!=ny)
        F[ny]=nx;
}
int main(){
	while(scanf("%d",&n),n){
        scanf("%d",&m);
        init();
        for(int i=1;i<=m;i++)
        {   int a,b;
            scanf("%d %d",&a,&b);
            vis[a]++; vis[b]++;
            Union(a,b);
        }
        int t=0;
        for(int i=1;i<=n;i++){
            if(F[i]==i)
                t++;
        }
        if(t>1)
            printf("0\n");
        else{
            bool K=false;
            for(int i=1;i<=n;i++)
                if(vis[i]%2==1)
                    K=true;
            if(K)
                printf("0\n");
            else
                printf("1\n");
        }
	}
	return 0;
}
