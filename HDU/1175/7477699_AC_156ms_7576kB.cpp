#include "cstdio"
#include "cstring"
using namespace std;
int Map[1010][1010];
int vis[1010][1010];
int xii[4]={1,0,-1,0};
int yii[4]={0,1,0,-1};
bool K;
int n,m;
void DFS(int x,int y,int xi,int yi,int gai,int t){
    //    printf("%d %d\n",x,y);
    if(t>2||K) return;
    if(x==xi&&y==yi){
        K=true;
        //        printf("%d\n",t);
        return ;
    }
    if(t==2)
    {
        if(x!=xi && y!=yi)	return;
        else if(x==xi){
            if(gai!=1)	return;}
        else if(y==yi)
                if(gai!=0)	return;
    }
    for(int i=0;i<4;i++){
        int nx=x+xii[i];
        int ny=y+yii[i];
        if(nx<1||ny<1||nx>n||ny>m||vis[nx][ny]==true)    continue;
        if(Map[nx][ny]==0||(nx==xi&&ny==yi)){
            vis[nx][ny]=true;
            if (gai==-1)  DFS(nx,ny,xi,yi,i%2,t);
            else if(gai==0)
            {
                if(i%2==1)  DFS(nx,ny,xi,yi,1,t+1);
                else	DFS(nx,ny,xi,yi,0,t);
            }
            else if(gai==1)
            {
                if(i%2==0)  DFS(nx,ny,xi,yi,0,t+1);
                else	DFS(nx,ny,xi,yi,1,t);
            }
            vis[nx][ny]=false;
        }
    }
    
}
int main(){
    while(scanf("%d %d",&n,&m),n||m){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&Map[i][j]);
        int q; scanf("%d",&q);
        while(q--){
            int x1,y1,x2,y2;scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            if(Map[x1][y1]!=Map[x2][y2]||Map[x1][y1]==0){
                puts("NO"); continue;
            }
            if(x1==x2&&y1==y2)
            {
                puts("NO");
                continue;
            }
            memset(vis, false, sizeof(vis));
            vis[x1][y1]=true; K=false;
            DFS(x1, y1, x2, y2, -1, 0);
            if(K)
                puts("YES");
            else
                puts("NO");
            
        }
    }
    return 0;
}