#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
int a[110];
int b[110];
int main(){
    memset(b,0,sizeof(b));
    bool K=false;
	int n; scanf("%d",&n);
	for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
	sort(a+1,a+n+1); int k=0;
	for(int i=1;i<=n;i++){
        if(b[k]!=a[i])
            b[++k]=a[i];
	}
	for(int i=2;i<k;i++)
        if(b[i-1]+1==b[i]&&b[i]==b[i+1]-1)
            K=true;
    if(K)
        printf("YES\n");
    else
        printf("NO\n");
	return 0;
}
