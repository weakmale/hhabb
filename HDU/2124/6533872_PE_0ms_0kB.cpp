#include<cstdio>
#include<algorithm>
using namespace std;
int a[666];
int main(){
	int l;
	int n;
	while(scanf("%d %d",&l,&n)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		int cnt=0;
		for(int i=n-1;i>=0;i--){
			l-=a[i];cnt++;
			if(l<=0)
				break ;
		}
		if(l>0)
			printf("impossible \n");
		else
			printf("%d\n",cnt);
	}
	return 0;
}