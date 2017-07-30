#include<cstdio>
int main(){
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		if(n==1) puts("-1");
		else if(n==2)
			printf("%d\n",m-1);
		else{
			int sum = n/2+1;
			if(n&1) sum++;
			if(sum>m) puts("-1");
			else printf("%d\n",m-sum);
		}
	}
}