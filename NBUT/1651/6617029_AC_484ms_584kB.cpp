#include<cstdio>
int n,m,k;
int num[100011];
int sum;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		sum=m;
		int max=0;
		for(int i=0;i<k;i++){
			scanf("%d",&num[i]);
			if(num[i]>max)
				max=num[i];
			sum-=num[i];
		}
		int y=n-k-1;
		if(max>=sum-y){
			printf("Impossible\n");
			continue;
		}
		if(y==0){
			printf("%d\n",sum);
			continue;
		}
		int l = max+1;  
        int r = sum - y;
		while (r >= l)  
        {  
            int mid = (l + r) >> 1;  
            if (sum - mid - y + 1 < mid)  
                r = mid - 1;  
            else  
                l = mid + 1;  
        }  
		printf("%d\n",l);
	}
}