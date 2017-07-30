#include<cstdio>
int main(){
	int n;
	scanf("%d",&n);
	int m[400]={0},f[400]={0};
	char sex[3];
	int x;
	int y;
	for(int i=0;i<n;i++){
		scanf("%s %d %d",sex,&x,&y);
		if(sex[0]=='M'){
			for(int j=x;j<=y;j++)
				m[j]++; 
		}
		if(sex[0]=='F'){
			for(int j=x;j<=y;j++)
				f[j]++;
		}
	}
	int Max=0;
	for(int i=0;i<400;i++){
		int max=0;
		if(f[i]==m[i])
			max=f[i]+m[i];
		if(max>Max)
			Max=max;
	}
	printf("%d\n",Max);
	return 0;
}