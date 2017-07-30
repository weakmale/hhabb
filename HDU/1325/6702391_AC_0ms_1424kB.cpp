#include <stdio.h>  
#include <string.h>  
int f[1001],g[1001];  
int find(int x)        
{  
    if(f[x]!=x)  
    f[x]=find(f[x]);  
    return f[x];  
}  
int main()  
{  
    int a,b,tt=1;  
    while(scanf("%d%d",&a,&b)!=EOF)  
    {  
        int i,flag=0,t=0;  
        if(a<0&&b<0)           
        break;  
        for(i=0;i<=1000;i++)  
        f[i]=i;  
        if(find(a)==find(b))  
        flag=1;  
        else  
        f[find(b)]=find(a);  
        while(scanf("%d%d",&a,&b))  
        {  
            if(a==0&&b==0)  
            break;  
            int aa,bb;  
            aa=find(a);  
            bb=find(b);  
            if(aa==bb||bb!=b)   
            flag=1;  
            else  
            f[bb]=aa;  
        }  
        memset(g,0,sizeof(g));  
        for(i=1;i<=1000;i++)    
        if(f[i]!=i)  
        g[find(i)]++;  
        for(i=1;i<=1000;i++)    
        if(g[i]>0)  
        t++;  
        if(t>1)  
        flag=1;  
        if(flag==1)  
        printf("Case %d is not a tree.\n",tt++);  
        else  
        printf("Case %d is a tree.\n",tt++);  
    }  
    return 0;  
}  