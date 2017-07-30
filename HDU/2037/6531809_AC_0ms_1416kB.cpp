#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int open;
	int end;
}a[111];
bool cmp(node a,node b){
	return a.end<b.end;
}
int main(){
	int t;
	while(~scanf("%d",&t),t){
		for(int i=0;i<t;i++)
			scanf("%d %d",&a[i].open,&a[i].end);
		sort(a,a+t,cmp);
		int cnt=1;
		int k=a[0].end;
		for(int i=0;i<t;i++){
			if(a[i].open>=k){
				cnt++;
				k=a[i].end;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}