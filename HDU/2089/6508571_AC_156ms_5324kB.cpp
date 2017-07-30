#include<cstdio>
int a[1000100]={0};
int b[7]={0};
void ji(){
	for(int i=1;i<1000100;i++){
		int t=i;
		int j=0;
		while(t){
			b[j]=t%10;
			t=t/10;
			j++;
		}
		for(int k=j-1;k>=0;k--){
			if(b[k]==4)
				a[i]=1;
			if(b[k]==6&&b[k-1]==2)
				a[i]=1;
		}
	}
}
int main(){
	ji();
	int m,n;
	while(scanf("%d%d",&m,&n)&&(m||n)){
		int t=0;
		for(int i=m;i<=n;i++)
			if(a[i]==0)
				t++;
		printf("%d\n",t);
	}
	return 0;
}