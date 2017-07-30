/*
	by:1879570236
	2016-4-7 22:47
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int a[10005],f[10005];
int ans[10005],num[10005]; 
int main(){
	int n,x,i,j,k,cnt=0;
	scanf("%d%d",&n,&x);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	f[0]=1;
	for(i=1;i<=n;i++){
		for(j=x;j>=a[i];j--){
			f[j]=f[j]+f[j-a[i]];
		}
	}//f[i]表示凑成i块钱的方案数 
	for(i=1;i<=n;i++){
		memset(ans,0,sizeof(ans));//ans[j]表示不用i号硬币凑成j元钱的方案数 
		for(j=0;j<=x;j++){
			if(j-a[i]>=0)ans[j]=f[j]-ans[j-a[i]];
			else ans[j]=f[j];
		} 
		if(ans[x]==0)num[++cnt]=a[i];
	}
	cout<<cnt<<endl;
	for(i=1;i<=cnt;i++)printf("%d ",num[i]);
}
/*
	by:1879570236
	2016-4-7 22:47
*/