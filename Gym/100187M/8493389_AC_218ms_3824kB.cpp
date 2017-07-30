#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>G1;
vector<int>G2;
int main(){
	int n; scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a,b; scanf("%d %d",&a,&b);
		if(a==-1) G2.push_back(b);
		else G1.push_back(b);
	}
	sort(G1.begin(),G1.end());
	sort(G2.begin(),G2.end());
	int z=G1.size()-1,f=G2.size()-1;
	int q; scanf("%d",&q);
	
	while(q--){
		int sum=0;
		int x; scanf("%d",&x);
		if(x>=0){
			int t=upper_bound(G1.begin(),G1.end(),x)-G1.begin();
			sum+=t;
			//printf("%d\n",t);
			x=-x;
			t=upper_bound( G2.begin(), G2.end(),x ) - G2.begin();

			sum+=t;
			
		}
		else{
			int t=upper_bound(G1.begin(),G1.end(),x)-G1.begin();
			sum+=t;
			x=-x;
			t=upper_bound(G2.begin(),G2.end(),x)-G2.begin();
			sum+=t;
		}
		printf("%d\n",sum);
	}
	return 0;
}