#include<cstdio>
int main(){
	int d1,d2,d3;
	while(~scanf("%d %d %d",&d1,&d2,&d3)){
		if(d3<d1+d2)
			printf("%d\n",d1+d2+d3);
		else
			printf("%d\n",(d1+d2)*2);
	}
	return 0;
}