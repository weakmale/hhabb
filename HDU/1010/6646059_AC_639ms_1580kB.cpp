#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int n,m,t;
char map[55][55];
bool vis[55][55];
int kx,ky,ex,ey;
bool P;
void DFS(int x,int y,int z){
    if(P==true)
        return ;
    if(map[x][y]=='D'&&z==t){
        P=true;
        return ;
    }
    int cnt=abs(x-ex)+abs(y-ey);
    if(cnt>t-z||(cnt+ t-z )%2!=0)
        return ;
    for(int i=0;i<4;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        
        if(map[xx][yy]!='X'&&xx>=0&&xx<n&&yy>=0&&yy<m&&!vis[xx][yy]){
            vis[xx][yy]=true;
            DFS(xx,yy,z+1);
            vis[xx][yy]=false;
        }
    }
}


int main()
{
    while(scanf("%d%d%d",&n,&m,&t)&&(n||m||t)){
        
        memset(vis,false,sizeof(vis));
        for(int i=0;i<n;i++){
            scanf("%s",map[i]);
            for(int j=0;j<m;j++){
                if(map[i][j]=='S')
                    kx=i,ky=j;
                if(map[i][j]=='D')
                    ex=i,ey=j;
            }
        }
        P=false;
        vis[kx][ky]=true;
        DFS(kx,ky,0);
        if(P){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
        
    }
    return 0;
}