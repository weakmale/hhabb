#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
struct node{
	int t;
	int you;
	bool friend operator <(node a, node b)
    {
        return a.you < b.you;
    }
}a;
int T;
node b;
char s[10];
int main(){
	priority_queue<node> cnt[4];
	scanf("%d",&T);
	int t=1;
	while(T--){
		
		int i;
		scanf("%s",s);
		if(strcmp(s,"IN")==0){
			scanf("%d%d",&i,&a.you);
			a.t=t;
			t++;
			cnt[i].push(a);
		}
		else{
			scanf("%d",&i);
			if(!cnt[i].empty()){
				b=cnt[i].top();
				printf("%d\n",b.t);
				cnt[i].pop();
			}
			else{
				printf("EMPTY\n");
			}
		}
	}
	return 0;
}