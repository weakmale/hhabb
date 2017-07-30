#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
int x,y;
int a[4];
int m[4];
void EXGCD(int a,int b){
    if(b==0)
    {
        x=1;y=0; return ;
    }
    EXGCD(b,a%b);
    int t=x;
    x=y;
    y=t-a/b*y;
}
int CRT(int n){
    int M=1;
    int ans=0;
    for(int i=1;i<=n;i++)
        M*=m[i];
    for(int i=1;i<=n;i++){
        int Mi=M/m[i];
        EXGCD(Mi,m[i]);
        ans=(ans+Mi*x*a[i])%M;
    }

    if(ans<0) ans+=M;
    return ans;
}
int main(){
    int p,e,i,d;int t=1;
	while(scanf("%d %d %d %d",&p,&e,&i,&d),p!=-1||e!=-1||i!=-1||d!=-1){
        a[1]=p;
        a[2]=e;
        a[3]=i;
        m[1]=23;
        m[2]=28;
        m[3]=33;
        int ans=CRT(3);
        if(ans<=d)
            ans+=21252;
        printf("Case %d: the next triple peak occurs in %d days.\n",t++,ans-d);
	}
	return 0;
}
