#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXX=10000+10;
int dp;
int a[MAXX];
int n;
int main(){
	while(scanf("%d",&n),n){
		cin>>a[1];
		dp=a[1];
		int maxx=a[1]; 
		int x=1;
		int y=1;
		int j=1;
		int t;
		if(a[1]<0)
			t=1;
		else
			t=0;
		for(int i = 2; i <= n; ++i ){
			cin>>a[i];
			if(a[i]<0)
				t++;
			if( dp+a[i] < a[i] ){
				dp=a[i];
				j=i;
			}
			else
				dp+=a[i];
			if( dp > maxx ){
				maxx=dp;
				x=j;
				y=i;
			}
		}
		if(t==n&&n!=1)
		{
			maxx=0; x=1; y=n;
		}
		cout<<maxx<<" "<<a[x]<<" "<<a[y]<<endl;
	}
	return 0;
}