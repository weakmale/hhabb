#include<cstdio>
#include<cmath>
int main()
{
	int m; scanf("%d",&m);
	while(m--){
		int n;
		scanf("%d",&n);
		int cnt[n],sum=0,ave=0,time=0,min=0;
		for(int i=0;i<n;i++)
			scanf("%d",&cnt[i]);
		for(int i=0;i<n;i++){
			min+=fabs(cnt[0]-cnt[i]);
		}
		for(int i=0;i<n;i++){
			time=0;
			for(int j=0;j<n;j++)
				time+=fabs(cnt[i]-cnt[j]);
			if(time<min)
				min=time;
		}
		printf("%d\n",min);
	}
	return 0; 
}