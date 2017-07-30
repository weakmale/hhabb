#include<cstdio>  
int GCD(int a, int b)  
{  
    if(a%b==0) 
		return b;  
    else  
    	return GCD(b, a%b);  
}  
int main()  
{  
    int t;  
    scanf("%d", &t);  
    while(t --){  
		int a, b, c;
        scanf("%d%d",&a,&b);  
        c= b*2;  
        while(GCD(a, c) != b){  
            c+=b;  
        }  
        printf("%d\n", c);  
    }  
    return 0;  
}  