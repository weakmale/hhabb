#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int ball[10000];
int b[1000];
int main(){
	while(~scanf("%d",&n)){
		memset(ball,0,sizeof(ball));
		memset(b,0,sizeof(b));
		int size;
		for(int i=0;i<n;i++)
			scanf("%d",&b[i]);
		
		sort(b,b+n);
		int k=0;
		for(int i=0;i<n;i++){
			if(b[i]!=b[i+1]){
				ball[k]=b[i];k++;}
		}
		for(int i=0;i<k;i++)
			printf("%d ",ball[i]);
		int y=0;
		for(int i=0;i<k-2;i++){
			if(ball[i]+1==ball[i+1]&&ball[i]+2==ball[i+2]){
				y=1;
				break;
			}
		}
		if(y)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}