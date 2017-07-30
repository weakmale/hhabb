#include<cstdio>
#include<cstring>
int x,y,k;
int map[200][200]={0};
int MAXX=0;
int c;
int xp[4]={-1,1,0,0};
int yp[4]={0,0,-1,1};
void DFS(int x1,int y1){
	
	if(map[x1][y1]==1&&x1>=1&&y1>=1&&x1<=x&&y1<=y){
		c++;
		map[x1][y1]=0;
		for(int i=0;i<4;i++){
			int xn=x1+xp[i];
			int yn=y1+yp[i];	
			DFS(xn,yn);		
		}
	}
}
int main(){
		scanf("%d%d%d",&x,&y,&k);
		memset(map,0,sizeof(map));
		for(int i=0;i<k;i++){
			int xi,yi;
			scanf("%d%d",&xi,&yi);
			map[xi][yi]=1;
		}
		MAXX=0;
		for(int i=1;i<=x;i++){
			for(int j=1;j<=y;j++){
				c=0;
				if(map[i][j]==1){
					DFS(i,j);
				}
				if(c>MAXX)
					MAXX=c;
			}
		}
		printf("%d\n",MAXX);
	return 0;
}