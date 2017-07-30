#include<cstdio>
typedef long long LL;
int num[20];
int Qpow(int n,int m){
	int ans=1;
	int base=n;
	while(m){
		if(m&1) ans = (ans*base)%10;
		base=(base*base)%10;
		m>>=1;
	}
	return ans;
}
int main()
{
    int T;
    int n,k;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&k);
        int s = n/10;
        int t=n%10;
        int sum=0;
        for(int i=1;i<=9;i++) num[i]=0;
        for(int i=1;i<=9;i++) num[i]=s;
        for(int i=1;i<=t;i++) num[i]++;
        for(int i=1;i<=9;i++)
        	if(num[i])
        		sum = (sum+Qpow(i,k)*num[i])%10;
		printf("%d\n",sum);
    }
    return 0;
}