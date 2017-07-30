#include<cstdio>
#include<cstring>
int a[11111]={1,1,0};
int b[11111];
void su(){
	for(int i=2;i<11111;i++){
		if(a[i])
			continue;
		for(int j=i+i;j<11111;j+=i)
			a[j]=1;
	}
}
int main(){
	su();
	int  n;
	while(~scanf("%d",&n),n){
		for(int i=2,j=n-2;i<j;i++,j--){
			if(a[i]==0&&a[j]==0&&i+j==n){
				b[n]++;}
		}
		printf("%d\n",b[n]);
		b[n]=0;
	}
	return 0;
}