#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXX=100000+10;
int dp;
int a;
int n;
int main(){
	int T; cin>>T; int t=1;
	while(T--){
		cin>>n;cin>>a;
		dp=a;int maxx=a; int x=1;int y=1;
		int j=1;
		for(int i = 2; i <= n; ++i ){
			cin>>a;
			if( dp+a < a ){
				dp=a;
				j=i;
			}
			else
				dp+=a;
			if( dp > maxx ){
				maxx=dp;
				x=j;
				y=i;
			}
		}
		cout<<"Case "<<t++<<":"<<endl<<maxx<<" "<<x<<" "<<y<<endl;  
		if(T)
		cout<<endl;
	}
	return 0;
}