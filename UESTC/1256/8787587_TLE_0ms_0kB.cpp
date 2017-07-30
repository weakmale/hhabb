#include<cstdio>
#include<map>
#include<set>
using namespace std;
int tree[2010*4];
set<int>s[2010*4];
void Upp(int rt){
	for(set<int>::iterator it = s[rt<<1].begin();it!=s[rt<<1].end();it++)
		s[rt].insert(*it);
	for(set<int>::iterator it = s[rt<<1|1].begin();it!=s[rt<<1|1].end();it++)
		s[rt].insert(*it);
}
void UP(int rt){
	for(set<int>::iterator it = s[rt].begin();it!=s[rt].end();it++)
		s[0].insert(*it);
}
void build(int l,int r,int rt){
	if(l==r){
		scanf("%d",&tree[rt]);
		s[rt].insert(tree[rt]);
		return;
	}
	int mid = (l+r)>>1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	Upp(rt);
}
void queue(int L,int R,int l,int r,int rt){
	if(l>=L&&r<=R){
		UP(rt); return;
	}
	int mid = (l+r)>>1;
	if(mid>=L) queue(L,R,l,mid,rt<<1);
	if(mid<R) queue(L,R,mid+1,r,rt<<1|1);
}
int main(){
	int n,m;
	while(scanf("%d %d",&n,&m) != EOF){
		build(1,n,1);
		int q; scanf("%d",&q);
		while(q--){
			s[0].clear();
			int l,r; scanf("%d %d",&l,&r);
			queue(l,r,1,n,1);
			printf("%d\n",s[0].size());
		}
	}
	return 0;
}