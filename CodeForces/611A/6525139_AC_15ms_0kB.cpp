#include<cstdio>
#include<cstring>
int main(){
	int n;
	char k[10];
	scanf("%d of %s",&n,k);
	if(strcmp(k,"week")){
		if(n==31)
				printf("7\n");
		else if(n==30)
				printf("11\n");
			
		else
			printf("12\n");
	}
	else{
		if(n==5||n==6)
			printf("53\n");
		else
			printf("52\n");
	}
	return 0;
}