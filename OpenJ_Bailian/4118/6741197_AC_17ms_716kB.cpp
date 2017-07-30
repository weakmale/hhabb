#include "cstdio"
#include "cstring"
#include "algorithm"
#include "iostream"
using namespace std;
const int MAXX=111;
int m[MAXX];
int pi[MAXX];
int pt[MAXX];
int main(){
    int T; int n,k;
    scanf("%d",&T);
    while(T--){
        memset(m, 0, sizeof(m));
        memset(pi, 0, sizeof(pi));
        memset(pt, 0, sizeof(pt));
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++){
          scanf("%d",&m[i]);
        }
//        int ans=0;
        for (int i=0; i<n; i++) {
            scanf("%d",&pi[i]);
        }
        for(int i=0;i<n;i++){
            int p=0;
            for(int j=0;j<i;j++){
                if(m[i]-m[j]>k&&pt[j]>p)
                    p=pt[j];
            }
            pt[i]=pi[i]+p;
            
        }
        int ans=0;
        for(int i=0;i<n;i++)
            ans=max(pt[i],ans);
        printf("%d\n",ans);
    }
    return 0;
}