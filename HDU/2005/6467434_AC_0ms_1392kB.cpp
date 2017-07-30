#include<cstdio>
int main(){
	int y,m,d;
	int day=0;
	int moth[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	while(~scanf("%d/%d/%d",&y,&m,&d)){
		day=0;moth[2]=28;
		if((y%4==0&&y%100!=0)||y%400==0)
		 	moth[2]=29;
		for(int i=0;i<m;i++)
			day+=moth[i];
		day=day+d;
		printf("%d\n",day);
	}
	return 0;
}