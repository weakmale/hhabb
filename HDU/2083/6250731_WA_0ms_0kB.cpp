#include<cstdio>
#include<cmath>
int main()
{
	int m; scanf("%d",&m);
	while(m--){
		int n;
		scanf("%d",&n);
		int cnt[n],sum=0,ave=0,time=0;
		for(int i=0;i<n;i++){
			scanf("%d",&cnt[i]);
			sum+=cnt[i];
		} 
		ave=sum/n;
		for(int i=0;i<n;i++)
			time+=fabs(cnt[i]-ave);
		printf("%d\n",time);
	}
	return 0; 
}