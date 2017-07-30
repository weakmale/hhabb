#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct node{
	char id[8];
	char nam[20];
	int ach;
}a[100100];
bool cmp1(node a,node b){
	return strcmp(a.id,b.id)<0;
}
bool cmp2(node a,node b){
	if(strcmp(a.nam,b.nam)==0)
		return strcmp(a.id,b.id)<0;
	return strcmp(a.nam,b.nam)<0;
}
bool cmp3(node a,node b){
	if(a.ach==b.ach)
		return strcmp(a.id,b.id)<0;
	return a.ach<b.ach;
		
}
int main(){
	int N,C;
	int t=1;
	while(~scanf("%d %d",&N,&C)){
		memset(a,0,sizeof(a));
		if(N==0){
			break;
		}
		for(int i=0;i<N;i++)
			scanf("%s %s %d",&a[i].id,a[i].nam,&a[i].ach);
		if(C==1)
			sort(a,a+N,cmp1);
		if(C==2)
			sort(a,a+N,cmp2);
		if(C==3)
			sort(a,a+N,cmp3);
		printf("Case %d:\n",t++);
		for(int i=0;i<N;i++)
			printf("%s %s %d\n",a[i].id,a[i].nam,a[i].ach);
	}
}