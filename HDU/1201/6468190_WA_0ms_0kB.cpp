#include<cstdio>
int main(){
	int t; scanf("%d",&t);
	int y,m,d;
	while(t--){
		int day=0;
		scanf("%d-%d-%d",&y,&m,&d);
		if(m==2&&d==29&&(y+18)%400!=0){
			printf("-1\n");
		}
		else{
		if((y%4==0&&y%100!=0)||y%400==0&&m<=2){
			day=day+366;
		}
		else if((y+18)%4==0&&(y+18)%100!=0||(y+18)%400==0&&m>2){
			day+=366;
		}
		else
			day+=365;
		y++;
		for(int i=0;i<17;i++){
			if((y%4==0&&y%100!=0)||y%400==0&&m<=2){
				day+=366;
			}
			else
				day+=365;
			y++;
		}
		printf("%d\n",day);
	}
	}
	return 0;
}