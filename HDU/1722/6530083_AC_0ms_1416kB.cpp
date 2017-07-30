
#include<cstdio>
int GCD(int a,int b)  
{  
    if(a%b==0) 
        return b;  
    else  
        return GCD(b,a%b);  
}  
int LCM(int a,int b){
	return a/GCD(a,b)*b;
}

int main(){
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF){
		printf("%d\n",m+n-GCD(m,n));
	}
	return 0;
}
