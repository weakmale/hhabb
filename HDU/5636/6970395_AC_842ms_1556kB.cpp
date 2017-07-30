#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
const LL mod=1e9+7;
LL a[10];
LL Map[10][10];
int main(){
	int T; scanf("%d",&T);
	while(T--){
        int n; int m; LL sum=0;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=6;i++){
            scanf("%lld",&a[i]);
        }
        for(int i=1;i<=6;i++){
            for(int j=1;j<=6;j++)
                Map[i][j]=abs(a[i]-a[j]);
        }
        Map[1][2]=Map[2][1]=1;
        Map[3][4]=Map[4][3]=1;
        Map[5][6]=Map[6][5]=1;
        for(int k=1;k<=6;k++)
            for(int i=1;i<=6;i++)
                for(int j=1;j<=6;j++)
                    Map[i][j]=min(Map[i][j],Map[i][k]+Map[k][j]);
        for(int i=1;i<=m;i++){
            LL x,y; scanf("%lld %lld",&x,&y);
            LL ans=abs(x-y);
            for(int k=1;k<=6;k++)
                for(int j=1;j<=6;j++)
                    ans=min(ans,abs(x-a[j])+Map[j][k]+abs(a[k]-y));
            sum=(sum+ans*i)%mod;
        }
        printf("%lld\n",sum);
	}
	return 0;
}
