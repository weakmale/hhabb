#include "cstdio"
#include "cstring"
#include "iostream"
using namespace std;
const int MAXX=111;
int m[MAXX];
int pi[MAXX];
int main(){
    int T; int n,k;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++){
          scanf("%d",&m[i]);
        }
        int ans=0;
        for (int i=0; i<n; i++) {
            scanf("%d",&pi[i]);
        }
        for(int i=0;i<n;i++){
            int p=0;
            for(int j=0;j<n;j++){
                if(m[i]-m[j]>k&&pi[j]>p)
                    p=pi[j];
            }
            if(pi[i]+p>ans)
                ans=pi[i]+p;
        }
        printf("%d\n",ans);
    }
    return 0;
}