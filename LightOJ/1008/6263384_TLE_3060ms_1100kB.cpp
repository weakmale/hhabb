#include<stdio.h>
#include<math.h>
int main()
{
	__int64 s,n,m,x,y,k=1,t;
	double a,b;
	scanf("%I64d",&t);
	while(t--)
	{
		scanf("%lf",&a); b=sqrt(a);n=b;s=a;
		printf("Case %I64d: ",k++);
		if(n*n==s)
		{
			if(n%2==0) {printf("%I64d 1\n",n);continue;}
			else {printf("1 %I64d\n",n); continue;}
		}
		n++;
		if(n*n-s<n)
		{
			x=n; y=n*n+1-s;
		}
		else {y=n;x=2*n-n*n-1+s;}
		if(n%2!=0){m=y;y=x;x=m;}
		printf("%I64d %I64d\n",x,y);
	}
	return 0;
}