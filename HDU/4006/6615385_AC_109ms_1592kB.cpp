#include<cstdio>
#include<queue>
using namespace std;
struct node{
	int x;
	bool friend operator <(node a,node b){
		return a.x>b.x;
	}
}a;
int n,k;
int main(){
	while(~scanf("%d %d",&n,&k)){
		priority_queue<node> cnt;
		char s[5];
		for(int i=0;i<n;i++){
			scanf("%s",s);
			if(s[0]=='I'){
				scanf("%d",&a.x);
				cnt.push(a);
				if(cnt.size()>k)
					cnt.pop();
			}
			else{
				a=cnt.top();
				printf("%d\n",a.x);
			}
		}
	}
	return 0;
}