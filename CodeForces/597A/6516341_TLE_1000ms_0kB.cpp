#include<cstdio>
int main()
{
	long long k,a,b;
	while(~scanf("%lld %lld %lld",&k,&a,&b))
	{
		int i=0;
		int cnt=0;
		if(a>=0){
			while(i<a)
				i+=k;
		}
		else{
			while(i>=a)
				i-=k;
			i+=k;
		}
		
		for(;i<=b;i+=k)
			cnt++;
		printf("%d\n",cnt);
	}
	return 0;
}