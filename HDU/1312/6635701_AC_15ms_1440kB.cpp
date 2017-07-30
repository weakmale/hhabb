#include<cstdio>
#include<cstring>
char map[300][300];
int m,n;
int x,y;
int cnt=0;
int xp[4]={-1,1,0,0};
int yp[4]={0,0,-1,1};
void DFS(int xi,int yi){
	for(int i=0;i<4;i++){
		int xn=xi+xp[i];
		int yn=yi+yp[i];
		if(map[xn][yn]=='.'&&xn>=0&&xn<m&&yn>=0&&yn<n){
			map[xn][yn]='#';
			cnt++;
			DFS(xn,yn);
		}
	}
}
int main(){
	while(scanf("%d%d",&n,&m)&&(n||m)){
        for(int i=0;i<m;i++)  
        {  
            getchar();  
            for(int j=0;j<n;j++)  
            {  
                scanf("%c",&map[i][j]);  
                if(map[i][j]=='@')  
                {  
                    x=i,y=j;  
                }  
            }  
        }  
        cnt=0;  
        DFS(x,y);  
        printf("%d\n",cnt+1);  
	}
	return 0;
}