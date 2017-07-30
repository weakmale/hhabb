#include<cstdio>
#include<cstring>
const int MAXX=100001;
int F[MAXX];
bool num[MAXX];
int l=0;
int d=0;
bool k=true;
void init(){
	for(int i=0;i<=MAXX;i++){
		 F[i] = i;num[i]=false; 
	}
	d=0;l=0;
}
int Found(int x){
	if(x==F[x])return x;
	F[x]=Found(F[x]);
	return F[x];
}
void Union(int x,int y){
	int nx=Found(x);
	int ny=Found(y);
	if(nx!=ny){
		F[ny]=F[nx];
		l++;
	}
	else
		k=false;
}
int main(){
	int x,y;
	while(~scanf("%d %d",&x,&y)){
		if(x==-1&&y==-1)
			break;
		init();
		k=true;
		if( x==0 && y==0 ){      
               printf("Yes\n");         
               continue;  
        }
		Union(x,y);
		num[x]=true;
		num[y]=true;
		while(scanf("%d %d",&x,&y),x||y){
			num[x]=true;
			num[y]=true;
			Union(x,y);
		}
		for(int i=0;i<=MAXX;i++)
			if(num[i]==1){
				d++;
			}
		if(k&&d==l+1){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	return 0;
}