#include<cstdio>  
int GCD(int a, int b)  
{  
    if(a%b==0) 
		return b;  
    else  
    	return GCD(b, a%b);  
}  
int LCM(int a,int b){
	return a/GCD(a,b)*b;
}
int main()  
{  
  	int a, b;
    while(~scanf("%d%d",&a,&b)){  
        printf("%d\n", LCM(a,b));  
    }  
    return 0;  
}  