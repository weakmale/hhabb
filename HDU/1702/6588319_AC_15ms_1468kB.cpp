#include<cstdio>
#include<stack>
#include<queue>
#include<cstring>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		char pro[10];
		int a;
		int n;
		scanf("%d%s",&n,pro);
		if(strcmp(pro,"FILO")==0){
			stack<int > cnt;
			for(int i=0;i<n;i++){
				scanf("%s",pro);
				if(strcmp(pro,"IN")==0){
					scanf("%d",&a);
					cnt.push(a);
				}
				else{
					if(!cnt.empty()){
						printf("%d\n",cnt.top());
						cnt.pop();
					}
					else{
						printf("None\n");
					}
				}
			}
		}
		else{
			queue<int > cnt;
			for(int i=0;i<n;i++){
				scanf("%s",pro);
				if(strcmp(pro,"IN")==0){
					scanf("%d",&a);
					cnt.push(a);
				}
				else{
					if(!cnt.empty()){
						printf("%d\n",cnt.front());
						cnt.pop();
					}
					else{
						printf("None\n");
					}
				}
			}
		}
	}
	return 0;
}