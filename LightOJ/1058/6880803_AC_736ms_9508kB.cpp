#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
struct node {
    int  x;int  y;
};
node di[1010];
node pare[1000010];
int n;
bool cmp(node a,node b){
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
int main(){
    int T,i,j,t=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for( i=1; i<=n;++i )
            scanf("%d %d",&di[i].x,&di[i].y);
        int k=0;
        for( i=1;i<=n;i++){
            for( j=i+1;j<=n;j++){
                pare[++k].x=di[i].x+di[j].x;
                pare[k].y=di[i].y+di[j].y;
            }
        }
        sort(pare+1,pare+k+1,cmp);
        int temp=1;
        int ans=0;
        for( i=2;i<=k;i++){
            if(pare[i].x==pare[i-1].x&&pare[i].y==pare[i-1].y)
                temp++;
            else{
                ans+=temp*(temp-1)/2;
                temp=1;
            }
        }
       printf("Case %d: %d\n",t++,ans);
    }
    return 0;
}
