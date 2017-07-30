#include "cstdio"
char Map[110][110];
int main(){
    int n,m; scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%s",Map[i]+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(Map[i][j]=='.'){
                if(i+j&1) Map[i][j]='B';
                else Map[i][j]='W';
            }
        }
        printf("%s\n",Map[i]+1);
    }
    return 0;
}
