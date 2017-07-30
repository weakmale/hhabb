#include<cstdio>
#include<cstring>
int n,k;
int map[10][10];
bool vis[10];
int cnt;
void DFS(int l){
	if(l==k){
		cnt++; return;
	}
	for(int i=0;i<n;i++){
		if(map[l][i]=='#'&&vis[i]==false){
			vis[i]=true;
			DFS(l+1);
			vis[i]=false;
		}
		
	}
}
int main(){
	while(scanf("%d%d",&n,&k)!=EOF){
		memset(vis,false,sizeof(vis));
		if(n==-1&&k==-1)
			break;
		for(int i=0;i<n;i++)  
        {  
            getchar();  
            for(int j=0;j<n;j++)  
                scanf("%c",&map[i][j]);  
        }  
        cnt=0;
		for(int i=0;i<=n-k;i++){
			DFS(i);
		}
		printf("%d\n",cnt);
	}
}