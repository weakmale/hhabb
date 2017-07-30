#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAXX=2000+10;
int s[MAXX];
int d[MAXX];
int dp[MAXX];
int n;
int main(){
	int T; cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>s[i];
		for(int i=1;i<n;i++)
			cin>>d[i];
		dp[1]=s[1];
		dp[0]=0;
		for(int i=2;i<=n;i++)
			dp[i]=min(dp[i-1]+s[i],dp[i-2]+d[i-1]);
		int ts=dp[n]%60;
		int tm=dp[n]/60;
		int th=tm/60+8;
		tm%=60;
		if(th<=12)
			printf("%02d:%02d:%02d am\n",th,tm,ts);
		else
			printf("%02d:%02d:%02d pm\n",th-12,tm,ts);
	}
	return 0;
}