#include<cstdio>
int a[111];
int main()
{
	int n;
	int i=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int sum=0;
	i=0;
	while(a[i]==0){
		sum++;i++;
	}
	int max=sum;
	int t=i;
	if(a[t]==3){
		a[i]=1;i++;
		for(;i<n;i++){
			if(a[i]==3){
				if(a[i-1]){
					if(a[i-1]==1)
						a[i]=2;
					if(a[i-1]==2)
						a[i]=1;
				}
				else {
				if(a[i+1]==1)
					a[i]=2;
				if(a[i+1]==2)
					a[i]=1;
				}
			}
			if(a[i]==a[i-1]&&a[i-1]!=3&&a[i-1])
				sum++;
			if(a[i]==0)
				sum++;
		}
		i=t;
		a[i]=2;i++;
		for(;i<n;i++){
			if(a[i]==3){
				if(a[i-1]){
					if(a[i-1]==1)
						a[i]=2;
					if(a[i-1]==2)
						a[i]=1;
				}
				else{
					if(a[i+1]==1)
						a[i]=2;
					if(a[i+1]==2)
						a[i]=1;
				}
			}
			if(a[i]==a[i-1]&&a[i-1]!=3&&a[i-1])
				max++;
			if(a[i]==0)
				max++;
		}
		if(max>sum);
			sum=max;
	}
	else{
		
		i++;
		for(;i<n;i++){
			if(a[i]==3){
				if(a[i-1]){
					if(a[i-1]==1)
						a[i]=2;
					if(a[i-1]==2)
						a[i]=1;
				}
				else{
				if(a[i+1]==1)
					a[i]=2;
				if(a[i+1]==2)
					a[i]=1;
				}
			}
			if(a[i]==a[i-1]&&a[i-1]!=3&&a[i-1])
				sum++;
			if(a[i]==0)
				sum++;
		}
	}
	printf("%d\n",sum);
	return 0;
}