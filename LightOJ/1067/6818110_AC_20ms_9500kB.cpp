#include<stdio.h>  
#include<iostream>  
#include<algorithm>  
using namespace std;  
const int maxn=1e6+5,mod=1000003;  
typedef long long LL;  
LL fact[maxn];//不明白为什么这里我用define定义maxn就不行   
void f()//打出阶乘表   
{  
    fact[1]=fact[0]=1;  
    for(LL  i=2;i<maxn;i++)  
    fact[i]=(i*fact[i-1])%mod;  
}  
LL niyuan(LL a,LL p)//快速幂  
{  
    LL res=1%mod;  
    LL t=a%mod;  
    while(p)  
    {  
        if(p%2)  
        res=res*t%mod;  
        t=t*t%mod;  
        p=p/2;  
    }  
    return res;  
}  
LL c(int n,int k)  
{  
    LL fm=(fact[k]*fact[n-k])%mod;  
    LL ans1=niyuan(fm,mod-2);//费马小定理，求一个幂就好;  
    return (ans1*fact[n])%mod;  
}  
int main()  
{  
    int t,n,k,kase=0;  
    f();  
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%d%d",&n,&k);  
        if(k*2>n)  
        k=n-k;//组合数对称性，减少计算；  
        printf("Case %d: %lld\n",++kase,c(n,k));  
    }  
    return 0;  
}