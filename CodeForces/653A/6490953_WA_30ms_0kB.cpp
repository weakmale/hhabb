#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int ball[100];
int main(){
	while(~scanf("%d",&n)){
		memset(ball,0,sizeof(ball));
		int size;
		int k=0;
		for(int i=0;i<n;i++){
			scanf("%d",&size);
			if(i==0)
				ball[k]=size;
			if(size!=ball[k]){
				ball[k+1]=size;k++;
			}
		}
		k++;
		sort(ball,ball+k);
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
}