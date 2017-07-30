#include<cstdio>
#include<cstring>
char map[150][150][150];
bool vis[150][150][150];
int L,R,C;
int sx,sy,sz;
int ex,ey,ez;
int xi[6]={1,-1,0,0,0,0};
int yi[6]={0,0,1,-1,0,0};
int zi[6]={0,0,0,0,-1,1};
int t;
void DFS(int x1 ,int y1 ,int z1, int temp){
	if(x1==ex&&y1==ey&&z1==ez){
		if(t>temp)
			t=temp;
		return ;
	}
	
	vis[z1][x1][y1]=false;
	for(int i=0;i<6;i++){
		int xn=x1+xi[i];
		int yn=y1+yi[i];
		int zn=z1+zi[i];
		if(xn>=0&&yn>=0&&zn>=0&&xn<R&&yn<C&&zn<L&&vis[zn][xn][yn]&&temp<t&&map[zn][xn][yn]=='.'||map[zn][xn][yn]=='E'){	
			DFS(xn,yn,zn,temp+1);		
		}	
	}
	vis[z1][x1][y1]=true;
}
int main(){
	while(scanf("%d %d %d",&L,&R,&C),C||L||R){
		for(int i=0;i<L;++i)
        {
            for(int j=0;j<R;++j)
            {
                scanf("%s",map[i][j]);
                for(int r=0;r<C;++r)
                {
                    if(map[i][j][r]=='S')
                    {
                        sz=i;
                        sx=j;
                        sy=r;
                    }
                    else if(map[i][j][r]=='E')
                    {
                        ez=i;
                        ex=j;
                        ey=r;
                    }
                }
            }
        }
		memset(vis,true,sizeof(vis));
		t=10000000;
		DFS(sx,sy,sz,0);
		if(t==10000000)
			printf("Trapped!\n");
		else
			printf("Escaped in %d minute(s).\n",t);
	}
	return 0;
}