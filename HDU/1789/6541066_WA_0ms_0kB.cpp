#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int day;
	int sco;
}a[1011];
bool cmp(node a,node b){
	if(a.day==b.day)
		return a.sco>b.sco;
	return a.day<b.day;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i].day);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i].sco);
		sort(a,a+n,cmp);
		
		int sum=0;
		int k=1;
		for(int i=0;i<n;i++){
			if(a[i].day>=k){
				k++;
				continue ;
			}
			int min=a[i].sco;
			int s=i;
			for(int j=i;j>=0;j--){
					if(min>a[j].sco){
						min=a[j].sco;s=j;
				}
			}
			sum+=min;
		}
		printf("%d\n",sum);
	}
	return 0;
}