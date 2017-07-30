#include<cstdio>
#include<queue>
using namespace std;
struct node{
	int l;
	bool friend operator < (node a,node b){
		return a.l>b.l;
	}
}a;
int main(){
	int n;
	while(~scanf("%d",&n)){
	priority_queue<node> cnt;
	for(int i=0;i<n;i++){
		scanf("%d",&a.l);
		cnt.push(a);
	}
	a=cnt.top();
	long long  sum=0;
	long long L=a.l;
	cnt.pop();
	while(!cnt.empty()){
		a=cnt.top();
		L=L+a.l;
		sum+=L;
		cnt.pop();
		}
	printf("%lld\n",sum);
	}
	return 0;
}