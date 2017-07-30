#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct node{
	char nam[20];
	double p;
	int  v;
	double c;
}a[111];
bool cmp(node a,node b){
	if(a.c==b.c)
		return a.v>b.v;
	return a.c<b.c;
}
int T;
int n;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%s %d %d",a[i].nam,&a[i].p,&a[i].v);
			if(a[i].v<200){
				i--;n--;
			}
			else{
				int d=a[i].v/200;
				if(d>5){
					a[i].c=a[i].p/5.0;
				}
				else
					a[i].c=a[i].p/d;
			}
		}
		sort(a,a+n,cmp);
		printf("%s\n",a[0].nam);
	}
	return 0;
}