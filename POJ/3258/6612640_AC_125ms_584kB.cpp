#include<cstdio>
#include<algorithm>
using namespace std;
int L,n,m;
int num[50055];
bool jugde(int mid){
	int last=0;//现在所在的位置 
	int sum=0;
	for(int i=0;i<n;i++){
		if(num[i]-last<mid){//如果这个位置的距离大于两个石头之间的距离直接跳过去 
			continue;
		}
		else{//否则所剩的石头数加一现在的距离变为所在的位置 
			sum++;last=num[i];
			if(L-num[i]<mid)break; //到岸上的距离也小于mid就直接上岸 
			
		}
	}
	return sum>=n-m;//石头剩的多了距离取小了 
}
int main(){
	while(~scanf("%d %d %d",&L,&n,&m)){
		for(int i=0;i<n;i++)
			scanf("%d",&num[i]);
		sort(num,num+n);
		int l=0;
		int r=L;
		int ans=0;
		while(l<=r){
			int mid=(l+r)/2;//二分牛每次走的最小距离 
			if(jugde(mid)){
				ans=mid;
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}