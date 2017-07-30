#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
double L,C,T;
int N;
double dp[110];
double c[110];
double VR,VT1,VT2;
int main(){
	while(~scanf("%lf",&L)){
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
				double cx=c[i]-c[j];
				double l=cx-C;
				double t;
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