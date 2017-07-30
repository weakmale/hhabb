#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int x,y,a,b,l;
int main(){
	while(~scanf("%d%d%d%d%d",&x,&y,&a,&b,&l)){
		if(a==b&&x!=y){
			printf("Impossible\n");
		}
		else{
			int s;
			int t;
			if(y>x){
				if(a>b){
					s=y-x;
					int si=a-b;
					int n=0;
					while((n*l+s)%si){
						n++;
					}
					t=(n*l+s)/si;
				}
				else{
					s=l-b+a;
					int si=b-a;
					int n=0;
					while((n*l+s)%si){
						n++;
					}
					t=(n*l+s)/si;
				}
			}
			else{
				if(b>a){
					s=x-y;
					int si=b-a;
					int n=0;
					while((n*l+s)%si){
						n++;
					}
					t=(n*l+s)/si;
				}
				else{
					s=l-x+y;
					int si=a-b;
					int n=0;
					while((n*l+s)%si){
						n++;
					}
					t=(n*l+s)/si;
				}
			}
			printf("%d\n",t);
		}
	}
	return 0;
}