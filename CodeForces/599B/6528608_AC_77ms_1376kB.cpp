#include<cstdio>
int a[100011]={0};
int b[100011]={0};
struct node{
	int I;
	int num;
}p[100011];
int main(){
	int m,n;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i].num);
		p[p[i].num].I=i;
		a[p[i].num]++;
	}
	int  sum=0;
	int temp=0;
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
		if(a[b[i]]==1)
			sum++;
		else if(a[b[i]]>1)
			temp++;
	}
	if(sum+temp<m)
		printf("Impossible\n");
	else if(temp>0)
			printf("Ambiguity\n");
	else{
		printf("Possible\n");
		int t=0;
		for(int i=1;i<=m;i++){
			if(t++)
				printf(" ");
			printf("%d",p[b[i]].I);
		}
		printf("\n");
	}
	return 0;
}