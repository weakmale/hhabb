#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n;
	while(scanf("%d",&n),n){
		int tm[1011]={0};
		int gm[1011]={0};
		for(int i=1;i<=n;i++)
			scanf("%d",&tm[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&gm[i]);
		sort(tm+1,tm+n+1,cmp);
		sort(gm+1,gm+n+1,cmp);
		int cnt=0;
		int l=1;
		int p=0;
		for(int i=1;i<=n;i++){
			if(tm[l]>gm[i])
			{cnt++;l++;}
			if(tm[l]==gm[i]){
				p++;l++;
			}
		} 
		printf("%d\n",(2*cnt-n)*200+p*200);
	}
	return 0;
}