#include<cstdio>
int GCD(int a,int b)  
{  
    int t;  
    if(a<b)  
    {  
        t=a;  
        a=b;  
        b=t;  
    }  
    if(b==0) 
        return a;  
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