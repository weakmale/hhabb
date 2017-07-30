#include "cstdio"
using namespace std;
char Map[2010][2010];
int main(){
    int T; scanf("%d",&T); int kcase=1;
    while(T--){
        int n; scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%s",Map[i]+1);
        bool K=true;
        for(int i=1;i<=n&&K;i++){
            for(int j=1;j<=n&&K;j++){
                if(Map[i][j]=='1'){
                    for(int k=1;k<=n&&K;k++)
                        if(Map[j][k]=='1'&&Map[k][i]=='1')
                            K=false;
                        
                }
            }
        }
        printf("Case #%d: ",kcase++);
        if(!K)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}