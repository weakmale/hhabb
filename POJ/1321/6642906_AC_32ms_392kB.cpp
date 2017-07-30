#include<cstdio>
#include<cstring>
int n,k;
int map[10][10];
bool vis[10];
int cnt;
int num;
void DFS(int l){
	if(num==k){
		cnt++; return;
	}
	else if(l>=n)
        return ;
       for(int i=0;i<n;i++)
        if(!vis[i] && map[l][i]=='#'){
            vis[i]=true;
            num++;
            DFS(l+1);
            vis[i]=false;
            num--;
        }
    DFS(l+1);   
}
int main(){
	while(scanf("%d%d",&n,&k)){
        getchar();
        if(n==-1 && k==-1)
            break;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                scanf("%c",&map[i][j]);
            getchar();
        }
        cnt=0;num=0;
		DFS(0);
		printf("%d\n",cnt);
	}
	return 0;
}