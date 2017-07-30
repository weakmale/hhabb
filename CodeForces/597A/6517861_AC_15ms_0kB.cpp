#include<cstdio>
int main()
{
	long long k,a,b;
	while(~scanf("%lld %lld %lld",&k,&a,&b))
	{
		if(a<0&&b>0){
			a=-a;
			printf("%lld\n",a/k+b/k+1);
		}
		else if(a<0&&b<=0){
			a=-a;b=-b;
			if(b%k==0)
				printf("%lld\n",a/k-b/k+1);
			else
				printf("%lld\n",a/k-b/k);
		}
		else{
			if(a%k==0)
				printf("%lld\n",b/k-a/k+1);
			else
				printf("%lld\n",b/k-a/k);
		}
	}
	return 0;
}