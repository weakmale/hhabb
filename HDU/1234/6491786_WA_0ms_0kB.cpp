#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	char id[20];
	int h[2];
	int m[2];
	int s[2];
}stu[1111];
bool cmp(node a,node b){
	if(a.h[0]!=b.h[0])
		return a.h[0]<b.h[0];
	if(a.m[0]!=b.m[0])
		return a.m[0]<b.m[0];
	if(a.s[0]<b.s[0])
		return a.s[0]<b.s[0];
}
bool cmp1(node a,node b){
	if(a.h[1]!=b.h[1])
		return a.h[1]<b.h[1];
	if(a.m[1]!=b.m[1])
		return a.m[1]<b.m[1];
	if(a.s[1]<b.s[1])
		return a.s[1]<b.s[1];
}
int n;
int m;
int main(){
	scanf("%d",&n);
	while(n--){
		memset(stu,0,sizeof(stu));
		scanf("%d",&m);
		for(int i=0;i<m;i++)
			scanf("%s %d:%d:%d %d:%d:%d",stu[i].id,&stu[i].h[0],&stu[i].m[0],&stu[i].s[0],&stu[i].h[1],&stu[i].m[1],&stu[i].s[1]);
		sort(stu,stu+m,cmp);
		printf("%s ",stu[0].id);
		sort(stu,stu+m,cmp1);
		printf("%s\n",stu[m-1].id);
	}
	return 0;
}