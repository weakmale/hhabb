#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXX=33;
const int inf=0x3f3f3f3f;
int map[MAXX][MAXX];
int pir[MAXX][MAXX];
int n;
int m;
void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)
				pir[i][j]=0;
			else
				pir[i][j]=inf;
		}
	}
}
int dis[MAXX];
bool vis[MAXX];
void dijkstra(){
	memset(vis,false , sizeof(vis));  memset(dis,inf,sizeof(dis));
	dis[1]=0;
	for(int i=0;i<n;i++){
		int k=-1;int M=inf;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&dis[j]<M){
				k=j;M=dis[j];
			}
		}
		if(k==-1)
			return ;
		vis[k]=true;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&dis[j]>dis[k]+map[k][j])
				dis[j]=dis[k]+map[k][j];
		}
	}
	
}
int main(){
	while(scanf("%d %d",&n,&m)!=EOF,n||m){
		init();
		for(int i=0;i<m;i++){
			int a,b,c;
			scanf("%d %d %d",&a ,&b ,&c);
			if(pir[a][b]>c)  
            	pir[a][b]=pir[b][a]=c;  
		}
		int maxx=0;
	 for(int i=2;i<n;i++)  
        {  
            for(int j=1;j<=n;j++)  
            {  
                for(int k=1;k<=n;k++)  
                {  
                    if(j==i||k==i)  
                    {  
                        map[j][k]=inf;  
                    }  
                    else  
                    {  
                        map[j][k]=pir[j][k];  
                    }  
                }  
            }  
            dijkstra();  
            maxx=maxx<dis[n]?dis[n]:maxx;  
        }  
		if(maxx==inf)
			printf("Inf\n");
		else
			printf("%d\n",maxx);
	}
	return 0;
}