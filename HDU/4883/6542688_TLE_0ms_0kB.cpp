#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int s;
	int open;
	int endl;
	int cha;
}a[10011];
bool cmp(node a,node b){
	if(a.cha==b.cha)
		return a.open<b.open;
	return a.cha>b.cha;
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n,x,y,x1,y1;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d %d:%d %d:%d",&a[i].s,&x,&y,&x1,&y1);
			a[i].open=x*100+y;
			a[i].endl=x1*100+y1;
			a[i].cha=a[i].endl-a[i].open;
		}
		sort(a,a+n,cmp);
		int Max=0;
		for(int i=0;i<n;i++){
			int max=a[i].s;
			for(int j=i+1;j<n;j++)
				if((a[i].open<a[j].open&&a[i].endl>a[j].open)||(a[i].endl>a[j].endl&&a[i].open<a[j].endl)||(a[i].endl==a[j].endl&&a[i].open==a[j].open))
					max+=a[j].s;
			if(Max<max)
				Max=max;
		}
		printf("%d\n",Max);
	}
}