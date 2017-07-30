#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int L;
int N,C,T;
int dp[110];
int c[110];
int VR,VT1,VT2;
int main(){
	while(~scanf("%d",&L)){
		cin>>N>>C>>T;
		cin>>VR>>VT1>>VT2;
		for(int i=1;i<=N;++i){
			cin>>c[i];
		}
		c[0]=0;
		c[N+1]=L;
		dp[0]=0;
		for(int i=1;i<=N+1;++i){
			dp[i]=c[i]/VT2;
			for(int j=0;j<i;j++){
				int cx=c[i]-c[j];
				int l=cx-C;
				int t;
				if(l>0)
					t=C/VT1+l/VT2;
				else
					t=cx/VT1;
				if(j==0)
					dp[i]=min(dp[j]+t,dp[i]);
				else
					dp[i]=min(dp[j]+t+T,dp[i]);
			}
		}
		if(dp[N+1]>L/VR)
			cout<<"Good job,rabbit!"<<endl;
		else
			cout<<"What a pity rabbit!"<<endl;
	}
	return 0;
}