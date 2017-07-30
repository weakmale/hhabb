#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int cx[] = {-1,1,0,0,0,0};
const int cy[] = {0,0,-1,1,0,0};
const int cz[] = {0,0,0,0,1,-1};
int l,r,c;
char map[100][100][100];
struct Node{
    int z,x,y;
    int step;
};
queue<Node> Q;
int x,y,z;
int ans;
void bfs(){
    while(!Q.empty()){
        Node tem = Q.front();Q.pop();
        int x = tem.x;
        int y = tem.y;
        int z = tem.z;
        int cnt = tem.step;
        for(int i = 0;i < 6;i++){
        	Node end;
            end.x = x + cx[i];
            end.y = y + cy[i];
            end.z = z + cz[i];
            end.step=cnt+1;
            if(map[end.z][end.x][end.y] == '.'){
                Q.push(end);
                map[end.z][end.x][end.y] = '#';
            }
            else if(map[end.z][end.x][end.y] == 'E'){
                ans = cnt+1;
                break;
            }
        }
        if(ans != -1) break;
    }
}

int main(){
    while(scanf("%d%d%d",&l,&r,&c)){
        if(l == 0 && r == 0 && c == 0) break;
        memset(map,-1,sizeof(map));
        while(!Q.empty()) Q.pop();
        for(int i = 1;i <= l;i++){
            for(int j = 1;j <= r;j++){
                scanf("%s",map[i][j]+1);
                for(int k = 1;k <= c;k++){
                    if(map[i][j][k] == 'S') 
                    {
                    	x=j;y=k;z=i;
					}
				}
            }
        }
        Node a;
        a.x=x;
        a.y=y;
        a.z=z;
        a.step=0;
        Q.push(a);
        ans = -1;
        bfs();
        if(ans == -1){
            printf("Trapped!\n");
        }
        else{
            printf("Escaped in %d minute(s).\n",ans);
        }
    }
    return 0;
}
