#include <cstdio>  
int main()  
{  
    long long ans = 0;  
    int n;  
    int a,b,c,d;  
    int e,f,i,h;  
    scanf ("%d %d %d %d %d",&n,&a,&b,&c,&d);  
    for (e = 1 ; e <= n ; e++) 
	{  
		f = e + b - c;  
        h = e + a - d;  
        i = f + a - d;  
        if (f >= 1 && f <= n && h >= 1 && h <= n && i >= 1 && i <= n)  
            ans++;  
    }  
	    ans *= n;  
    printf ("%ld\n",ans);  
    return 0;  
}  
