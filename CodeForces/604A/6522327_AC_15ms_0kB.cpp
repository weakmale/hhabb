#include<cstdio>
int  Max(int  a,int  b){
	if(a>b)
		return a;
	else 
		return b;
}
int main(){
	int  m[6];
	int  w[6];
	int  h1,h2;
	int  sum=0;
	scanf("%d %d %d %d %d",&m[1],&m[2],&m[3],&m[4],&m[5]);
	scanf("%d %d %d %d %d",&w[1],&w[2],&w[3],&w[4],&w[5]);
	scanf("%d %d",&h1,&h2);
	for(int i=1;i<6;i++){
		sum+=Max(50*i*3,500*i-2*m[i]*i-50*w[i]);
	}
	printf("%d\n",sum+h1*100-h2*50);
}