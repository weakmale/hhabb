#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	char id[20];
	int h[2];
	int m[2];
	int s[2];
}stu[1000];
bool cmp(node a,node b){
	if(a.h[0]!=b.h[0])
		return a.h[0]<b.h[0];
	else if(a.m[0]!=b.m[0])
		return a.m[0]<b.m[0];
	else if(a.s[0]!=b.s[0])
		return a.s[0]<b.s[0];
}
bool cmp1(node a,node b){
	if(a.h[1]!=b.h[1])
		return a.h[1]>b.h[1];
	else if(a.m[1]!=b.m[1])
		return a.m[1]>b.m[1];
	else if(a.s[1]!=b.s[1])
		return a.s[1]>b.s[1];
}

int main(){
	int n;
	int x;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		for(int i=0;i<x;i++)
			scanf("%s %d:%d:%d %d:%d:%d",stu[i].id,&stu[i].h[0],&stu[i].m[0],&stu[i].s[0],&stu[i].h[1],&stu[i].m[1],&stu[i].s[1]);
		sort(stu,stu+x,cmp);
		printf("%s ",stu[0].id);
		sort(stu,stu+x,cmp1);
		printf("%s\n",stu[0].id);
	}
	return 0;
}