#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
const int INF=0x3f3f3f3f;
int n;
int s;
int a[100000+10];
int c1[100000+10];
int c2[100000+10];
int c3[100000+10];
int main(){
	while(~scanf("%d %d",&n,&s)){
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            c1[i]=INF;c2[i]=0;
        }
        c2[1]=1;c1[1]=a[1];
        int ans=0;
        for(int i=2;i<=n;i++){
            int k=lower_bound(c1+1,c1+1+n,a[i])-c1;
            if(i-c2[k-1]>d){
                c2[k]=min(c2[k],i);
                c1[k]=min(c1[k],a[i]);
                ans=max(k,ans);
            }
        printf("%d\n",ans);
	}
	return 0;
}
