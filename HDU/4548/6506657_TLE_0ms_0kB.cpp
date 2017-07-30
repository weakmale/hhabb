#include<cstdio>
int a[1000000]={1,1,0};
void su(){
	for(int i=2;i<1000000;i++){
		if(a[i])
			continue;
		for(int j=i+i;j<1000000;j+=i)
			a[j]=1;
	}
}
bool mei(int c){
	if(a[c])
		return false;
	else{
		int x=0;
		while(c/10){
			x=x+c/10;
			c=c%10;
		}
		int t=c+x;
		if( a[t] )
			return false;
		else
		return true;
	}
}
int main(){
	su();
	int k=0;
	int t; scanf("%d",&t);
	while(t--){
		int m,n;
		scanf("%d%d",&m,&n);
		int l=0;
		for(int i=m;i<=n;i++){
			if(mei(i)){
				l++;
			}
		}
		printf("Case #%d: %d\n",++k,l);
	}
	return 0;
}