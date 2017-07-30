#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct node{
	char nam[55];
	int sco;
	int r;
};
bool cmp(node a,node b){
	if(a.sco==b.sco)
		return a.r<b.r;
	return a.sco>b.sco;
}
node a[500];
node b[500];
int n;
int main(){
	while(~scanf("%d",&n)){
		int y=1;
		for(int i=0;i<n;i++){
			scanf("%s %d",a[i].nam,&a[i].sco);
			a[i].r=i;
		}
		for(int i=0;i<n;i++){
			scanf("%s %d",b[i].nam,&b[i].sco);
			b[i].r=i;
		}
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++){
			if(a[i].sco!=b[i].sco){
				y=0;break;
			}
		}
		if(y){
			for(int i=0;i<n;i++){
				if(strcmp(a[i].nam,b[i].nam)){
					y=0;break;}
			}
			if(y)
				printf("Right\n");
			else{
				printf("Not Stable\n");
				for(int i=0;i<n;i++)
					printf("%s %d\n",a[i].nam,a[i].sco);
			}
		}
		else{
			printf("Error\n");
				for(int i=0;i<n;i++)
					printf("%s %d\n",a[i].nam,a[i].sco);
		}
	}
	return 0;
}