#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
int a[15];
int w[15];
int x,y;
int EXGCD(int a,int b){
    if(b==0){
        x=1;y=0; return a;
    }
    int r=EXGCD(b,a%b);
    int t=x;
    x=y;
    y=t-a/b*y;
    return r;
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
        int n; int m; scanf("%d %d",&n,&m);
        for(int i=1;i<=m;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=m;i++)
            scanf("%d",&w[i]);
        int a1=a[1]; int b1=w[1]; int a2,b2; bool K=false;int d;
        for(int i=2;i<=m;i++){
            a2=a[i]; b2=w[i];
            d=EXGCD(a1,a2);
            int c=b2-b1;
            if(c%d)
            {
                K=true; break;
            }
            x=x*(c/d);
            a2/=d;
            x=(x%a2+a2)%a2;
            b1=x*a1+b1;
            a1*=a2;
        }
        if(K||b1>n)
            printf("0\n");
        else{
            int ans=(n-b1)/a1+1;
            if(b1==0) ans--;
            printf("%d\n",ans);
        }
	}
	return 0;
}
