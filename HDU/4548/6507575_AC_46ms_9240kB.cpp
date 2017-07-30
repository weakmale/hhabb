#include<cstdio>
#include<cmath>
int a[1000001]={1,1,0};
int b[1000001]={0};
void su(){
	for(int i=2;i<floor(sqrt(1000001)+0.5);i++){
		if(a[i])
			continue;
		for(int j=i+i;j<1000001;j+=i)
			a[j]=1;
	}
}
int sum(int a)  
{  
	int y=0;  
	while(a)  
	{  
    	y+=(a%10);  
    	a/=10;  
	}  
 	return y;  
}  
int main(){
	su();
	int k=0;
	for(int i=1;i<1000001;i++){
		if(!a[i]&&!a[sum(i)])
			b[i]=b[i-1]+1;
		else
			b[i]=b[i-1];
	}
	int t; scanf("%d",&t);
	while(t--){
		int m,n;
		scanf("%d%d",&m,&n);
		printf("Case #%d: %d\n",++k,b[n]-b[m-1]);
	}
	return 0;
}