#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXX=102;
const int inf=0x3f3f3f3f;
int n,m;
int map[MAXX][MAXX];
void floyd(){
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
			}
		}
	}
}
int main(){
	while(~scanf("%d %d",&n,&m)){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				map[i][j]=i==j?0:inf;
			}
		}
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d %d" ,&a ,&b);
			map[a][b]=1;
			map[b][a]=1;
		}
	floyd();
	int flag=1;
	for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(map[i][j] > 7)
            {
                flag = 0;
                break;
            }
        }
        if(flag==0)
          	break;
   	}
    	if(flag==1)
        	printf("Yes\n");
    	else if(flag==0)
        	printf("No\n");
	}
	return 0;
}
