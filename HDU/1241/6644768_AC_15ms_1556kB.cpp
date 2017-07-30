#include<cstdio>
#include<cstring>
int m,n;
char map[150][150];
int sum=0;
int xi[8]={1,-1,0,0,1,1,-1,-1};
int yi[8]={0,0,-1,1,1,-1,1,-1};
int cnt[150];
bool vis[150][150];
void DFS(int x1,int y1){
for(int i=0; i<8; ++i){  
        int xn=x1+xi[i], yn=y1+yi[i];  
        if(xn>=0 && xn<m && yn>=0 && yn<n && map[xn][yn]=='@' && !vis[xn][yn]){  
            vis[xn][yn] = true;  
            DFS(xn, yn);  
        }  
    }  
}
int main(){
	while(~scanf("%d%d",&m,&n),n||m){
		for(int i=0;i<m;i++)
			scanf("%s",map[i]);
		memset(cnt,0,sizeof(cnt));
		memset(vis,false,sizeof(vis));
		int t=0;
		int ans=0;
		for(int i=0;i<m;i++){
			
			for(int j=0;j<n;j++)
			{	
				sum=0;
				if(map[i][j]=='@'&&!vis[i][j]){
					DFS(i,j);
					ans++;
				}	
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}