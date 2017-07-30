#include<cstdio>
#include<cstring>
int a[1500];
int main(){
	int T; scanf("%d",&T);
	while(T--){
		memset(a,0,sizeof(a));
		int n,x,y,x1,y1;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			int cnt=0;
			scanf("%d %d:%d %d:%d",&cnt,&x,&y,&x1,&y1);
			int open=x*60+y;
            int endl=x1*60+y1;
            for(int i=open;i<endl;i++)
            	a[i]+=cnt;
		}
		int Max=0;
		for(int i=0;i<1500;i++){
			if(a[i]>Max)
				Max=a[i];
		}
		printf("%d\n",Max);
	}
}