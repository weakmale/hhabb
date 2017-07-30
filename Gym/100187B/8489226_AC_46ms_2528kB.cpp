#include<cstdio>
#include<iostream>
using namespace std;
//const int K = 3e5 + 10;
int sum[100];
int vis[100];
int main(){
	string s; cin>>s;
	int n=s.size();
	for(int i=0;i<s.size();i++)
		sum[s[i]-'a']++;
	double ans = 0;
	for(int i=0;i<s.size();i++){
		if(!vis[s[i]-'a']){
			vis[s[i]-'a']=1;
			double cut = (double)(sum[s[i] - 'a'] * 1.0) / (double) n;
		    ans += cut * sum[s[i] - 'a'];
		}
	}
	printf("%.10lf\n",ans);
}