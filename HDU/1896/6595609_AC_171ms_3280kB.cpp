#include<cstdio>
#include<queue>
struct node{
	int l;
	int f;
	bool friend operator < (node a,node b){
		if(a.l==b.l)
			return a.f>b.f;
		return a.l>b.l;
	}
}a;
using namespace std;
int main(){
	priority_queue<node> cnt;
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int i=1;
		for(i=1;i<=n;i++){
			scanf("%d%d",&a.l,&a.f);
			cnt.push(a);
		}
		int sum=0;
		i=1;
		while(!cnt.empty()){
			a=cnt.top();
			if(i&1){
				sum=a.l+a.f;
				a.l=a.l+a.f;
				cnt.pop();
				cnt.push(a);
			}
			else{
				cnt.pop();
			}
			i++;
		}
		printf("%d\n",sum);
	}
}