#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int a[100];
int b[100];
int main(){
	int T; scanf("%d",&T);int t=1;
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<n;i++)
			scanf("%d",&b[i]);
		sort(a,a+n);
		sort(b,b+n);
		int a1=0,a2=n-1;
		int b1=0,b2=n-1;
		int f=0;  int p=0;
		while(a1<=a2){
			if(a[a2]>b[b2]){
				a2--;
				b2--;
				f++;
			}
			else if(a[a1]>b[b1]){
				a1++;
				b1++;
				f++;
			}
			else if(a[a1]<=b[b1]){
				if(a[a1]==b[b2])
					p++;
				a1++;
				b2--;
			}
		}
		printf("Case %d: %d\n",t++,f*2+p);
	}
	return 0;
}