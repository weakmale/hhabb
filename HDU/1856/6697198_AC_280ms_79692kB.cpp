#include<stdio.h>  
const int N=10000000;
int father[N],num[N];  
void init() 
{  
    int i;  
    for(i=1;i<=N;i++)  
    {  
        father[i]=i;  
        num[i]=1; 
    }  
}  
int Found(int x)  
{  
    if(father[x]!=x)  
        father[x]=Found(father[x]);  
    return father[x];  
}  
void Union(int a,int b)
{  
    int p=Found(a);  
    int q=Found(b);  
    if(p!=q)  
    {  
        father[p]=q;  
        num[q]+=num[p];
    }  
}  
int main()  
{  
    int n,a,b,i,sum,max;  
    while(~scanf("%d",&n))  
    {  
        if(n==0)  
        {  
            printf("1\n");  
            continue;  
        }  
        max=0;  
        init(); 
        for(i=0;i<n;i++)  
        {  
            scanf("%d%d",&a,&b);  
            if(a>max)  
                max=a;  
            if(b>max)  
                max=b;  
            Union(a,b); 
        }  
        int Max=0;  
        for(i=1;i<=max;i++)  
            if(num[i]>Max)  
                Max=num[i];  
        printf("%d\n",Max);  
    }  
    return 0;  
}  