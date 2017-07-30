#include<cstdio>
int main(){
	int n,k; scanf("%d %d",&n,&k);
	int num = n/k;
	int t = n%k;
	if(t==0) t=k,num--;
	num+=t-1;  
	if(k==n) puts("-1");
	else 
	printf("%d\n",num);
	return 0;
}