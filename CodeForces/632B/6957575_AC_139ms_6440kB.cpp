#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
const int MAXN=5e5+10;
long long a[MAXN];
char sr[MAXN];
int main(){
	int n;    long long sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    scanf("%s",sr);
    for(int i=0;i<n;i++)
        if(sr[i]=='B')
            sum+=a[i];
    long long l=sum;
    long long t=sum;

    for(int i=0;i<n;i++){
        if(sr[i]=='A')
            t+=a[i];
        else
            t-=a[i];
        sum=max(sum,t);
    }
    t=l;
    for(int i=n-1;i>=0;i--){
        if(sr[i]=='A')
            t+=a[i];
        else
            t-=a[i];
        sum=max(sum,t);
    }
    printf("%lld\n",sum);
	return 0;
}
