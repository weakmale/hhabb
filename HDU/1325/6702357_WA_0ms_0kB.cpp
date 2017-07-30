#include <stdio.h>  
#include <string.h>  
int f[1001],g[1001];  int k=0;
int Found(int x)       
{  
    if(f[x]!=x)  
    	f[x]=Found(f[x]);  
    return f[x];  
}
void Union(int a,int b){
	int aa,bb;  
    aa=Found(a);  
    bb=Found(b);  
    if(aa==bb||bb!=b)   
    	k=1;  
    else  
    	f[bb]=aa;  
}
int main()  
{  
    int a,b,tt=1;  
    while(scanf("%d%d",&a,&b)!=EOF)  
    {  
        int i,t=0;  
        if(a<0&&b<0)            
        	break;  
        for(i=0;i<=1000;i++)  
        	f[i]=i;  
        if(Found(a)==Found(b))  
       		 k=1;  
        else  
        	f[Found(b)]=Found(a);  
        while(scanf("%d%d",&a,&b))  
        {  
            if(a==0&&b==0)  
            break;  
            Union(a,b);

        }  
        memset(g,0,sizeof(g));  
        for(i=1;i<=1000;i++)    
        if(f[i]!=i)  
        	g[Found(i)]++;  
        for(i=1;i<=1000;i++)    
        	if(g[i]>0)  
       			t++;  
        if(t>1)  
       	 	k=1;  
        if(k==1)  
        	printf("Case %d is not a tree.\n",tt++);  
        else  
        	printf("Case %d is a tree.\n",tt++);  
    }  
    return 0;  
}  