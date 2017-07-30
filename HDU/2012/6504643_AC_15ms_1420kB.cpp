#include<cstdio>
int a[3000]={1,1,0};
int main(){
	int x,y;
	for(int i=2;i<3000;i++){
			if(a[i])
			continue ;
			for(int j=2*i;j<3000;j+=i){
				a[j]=1;
			}
		}
	while(~scanf("%d%d",&x,&y)){
		if(x==0&&y==0)
			break ;
		int t=1;
		for(int i=x;i<=y;i++){
			if(a[i*i+41+i])
				t=0;
		}
		if(t)
			printf("OK\n");
		else 
			printf("Sorry\n");
	}
	return 0;
}