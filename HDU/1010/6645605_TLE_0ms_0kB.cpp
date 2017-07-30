#include "cstdio"
#include "cstring"
int m,n,k;
char map[10][10];
int xi[4]={1,-1,0,0};
int yi[4]={0,0,1,-1};
bool vis[10][10];
int sum;
bool P=false;
void DFS(int x1,int y1){
    if(sum==k&&map[x1][y1]=='D'){
        P=true;
    }
    for(int i=0;i<4;i++){
        int xn=x1+xi[i];
        int yn=y1+yi[i];
        if (xn>=0&&yn>=0&&xn<m&&yn<n&&map[xn][yn]!='X'&&!vis[xn][yn]&&sum<k){
            sum++;
            vis[xn][yn]=true;
            DFS(xn, yn);
            vis[xn][yn]=false;
            sum--;
        }
    }
}
int main( ){
    while(scanf("%d%d%d",&m,&n,&k),m||n||k){
        int x=0,y=0;
        P=false;
        sum=0;
        memset(vis, false , sizeof(vis));
        for(int i=0;i<m;i++){
            getchar();
            for(int j=0;j<n;j++){
                scanf("%c",&map[i][j]);
                if (map[i][j]=='s') {
                    x=i;y=j;
                }
            }
        }
        vis[x][y]=true;
        DFS(x,y);
        if(P)
            printf("YES\n");
        else
            printf("NO\n");
        
    }
    return  0;
}