#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;
const int MAXX=100000+10;
int  L[MAXX];
int  C[MAXX];
int N,M,K,Q;
int main(){
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d %d %d %d", &N, &M, &K, &Q);
        memset(L,false,sizeof(L));
        memset(C,false,sizeof(C));
        int x1,y1,x2,y2;
        for(int i=0;i<K;i++){
            scanf("%d %d",&x1,&y1);
            C[x1]=1; L[y1]=1;
        }
        for(int i=1;i<=N;i++)
            C[i]+=C[i-1];
        for(int i=1;i<=M;i++)
            L[i]+=L[i-1];
        for(int i=0;i<Q;i++){
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            if(C[x2]-C[x1-1]==x2-x1+1||L[y2]-L[y1-1]==y2-y1+1)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
