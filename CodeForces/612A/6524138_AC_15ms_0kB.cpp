#include<cstdio>
#include<cstring>
int main(){
	int a,p,q;
	scanf("%d%d%d",&a,&p,&q);
	char str[a+5];
	scanf("%s",str);
	int i=0,j=0;
	bool k=false;
	while(j<=a){
		i=0;
		while(i<=a){
			if(i+j==a){
				k=true; break;
			}
			i+=p;
			
		}
		if(k)
			break;
		else
			j+=q;
	}
	if(k){
		printf("%d\n",i/p+j/q);
		for(int l=0;l<a;){
			printf("%c",str[l]);
			l++;
			if(l<=i&&l%p==0)
				printf("\n");
			if(l>i&&(l-i)%q==0)
				printf("\n");
		}
	}
	else
		printf("-1\n");
	return 0;
	
}