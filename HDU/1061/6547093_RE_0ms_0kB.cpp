#include<cstdio>
int main(){
	int t;
	scanf("%d",t);
	while(t--){
		int n;
		scanf("%d",&n);
		int t=n%10;
		int l=n%10;
		for(int i=1;i<n;i++){
			l=l*t;
			l=l%10;
			
		}
		printf("%d\n",l);
	}
}