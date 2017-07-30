#include<cstdio>
int main(){
	int d1,d2,d3;
	while(~scanf("%d %d %d",&d1,&d3,&d2)){
		int a=0;
		int b=0;
		a=d1;
		b=d3;
		if(d2+d3<d2*2+d1)
			a+=d2+d3;
		else
			a+=d2*2+d1;
		if(d1+d2>d3+d1*2)
			b+=d3+d1*2;
		else
			b+=d1+d2;
		if(a<b)
			printf("%d\n",a);
		else
			printf("%d\n",b);
	}
	return 0;
}