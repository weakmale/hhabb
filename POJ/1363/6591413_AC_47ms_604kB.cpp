#include<cstdio>
#include<stack>
using namespace std;
int main(){
	int n;
	while(~scanf("%d",&n),n){
		int a[1005];
		bool k=true;
		while(scanf("%d",&a[0]),a[0]){
			stack<int> cnt;
			int j,t;
			for(int i=1;i<n;i++)
				scanf("%d",&a[i]);
			for(j=1,t=0;j<=n;j++){
				cnt.push(j);
				while(cnt.top()==a[t]&&!cnt.empty()){
					t++;
					cnt.pop();
					if(cnt.empty())
						break;
				}
			}
			if(cnt.empty())
				printf("Yes\n");
			else
				printf("No\n");
		}
		printf("\n");
	}
	return 0;
}