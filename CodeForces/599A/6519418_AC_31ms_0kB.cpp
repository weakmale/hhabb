#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int a[3];
	while(~scanf("%d %d %d",&a[0],&a[1],&a[2])){
		sort(a,a+3);
		if(a[0]+a[1]<a[2])
			printf("%d\n",(a[0]+a[1])*2);
		else
			printf("%d\n",a[0]+a[1]+a[2]);
	} 
	return 0;
} 