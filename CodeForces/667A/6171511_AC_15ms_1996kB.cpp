
#include<stdio.h>  
#define PI 3.1415926  
int main()  
{  
    double d,h,v1,e;  
    double t;  
    while(scanf("%lf%lf%lf%lf",&d,&h,&v1,&e)!=EOF)  
    {  
        double s=PI*d*d*0.25;  
        double v=s*h;  
        double v2=s*e;  
        if(v2>=v1)  
            printf("NO\n");  
        else  
       {  
            t=v/(v1-v2);  
            printf("YES\n%lf\n",t);  
        }  
    }  
    return 0;  
} 
