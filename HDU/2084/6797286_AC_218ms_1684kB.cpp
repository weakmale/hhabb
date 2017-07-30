#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int a[110][110];
int dp[110][110];
int n;
int main(){
	int T;cin >> T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++)
				cin>>a[i][j];
		}
		for(int i=1;i<=n;i++){
			dp[n][i]=a[n][i];
		}
		for(int i=n-1;i>0;--i){
			for(int j=1;j<=i;j++){
				dp[i][j]=max( dp[i+1][j+1], dp[i+1][j] ) + a[i][j];
				
			}
		}
		cout<<dp[1][1]<<endl;
	}
	return 0;
}