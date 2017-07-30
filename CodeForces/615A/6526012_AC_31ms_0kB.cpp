#include<cstdio>
int main(){
	int n,m;
	int a[111]={0};
	int x;
	int y;
	bool t=true;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		for(int j=0;j<x;j++){
			scanf("%d",&y);
				a[y]++;
		}
	}
	for(int i=1;i<=m;i++){
		if(a[i]==0)
			t=false;
	}
	if(t)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
	