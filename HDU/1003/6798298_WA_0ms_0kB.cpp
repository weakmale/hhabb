#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXX=100000+10;
int dp[MAXX];
int a[MAXX];
int n;
int main(){
	int T; cin>>T; int t=1;
	while(T--){
		cin>>n;
		printf("Case %d:\n",t++);
		dp[0]=0;
		for(int i = 1; i <= n; ++i ){
			cin>>a[i];
			dp[i]=max(dp[i-1]+a[i],a[i]);
			if(dp[i-1]+a[i]>=a[i]){
				a[i]=0;
			}
			else{
				a[i]=1;
			}
		}
		int maxx=0; int x;int y;
		for(int i=1; i <= n; ++i){
			if(dp[i]>maxx)
			{
				maxx=dp[i]; x=i;
			}
		}
		y=x;
		while(a[y]==0&&y>1)
			y--;
		cout<<maxx<<" "<<y<<" "<<x<<endl;
		cout<<endl;
	}
	return 0;
}