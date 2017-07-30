#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n;
	while(scanf("%d",&n),n){
		int tm[1011]={0};
		int gm[1011]={0};
		for(int i=1;i<=n;i++)
			scanf("%d",&tm[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&gm[i]);
		sort(tm+1,tm+n+1);
		sort(gm+1,gm+n+1);
		int sum=0;
		 for(int i=1,j=n,i1=1,j1=n;i1<=j1&&i<=j;)
            {

                if(tm[i]>gm[i1])
                {
                    i++;
                    i1++;
                    sum++;
                }
                else if(tm[i]<gm[i1])
                {
                    i++;
                    j1--;
                    sum--;
                }
                else if(tm[j]>gm[j1])
                {
                    j--;
                    j1--;
                    sum++;
                }
                else if(tm[j]<gm[j1])
                {
                   i++;
                   j1--;
                   sum--;
                }
                else if(tm[i]<gm[j1])
                {
                    i++;
                    j1--;
                    sum--;
                }
                else
                {
                    i++;
                    j1--;
                }
            }
		printf("%d\n",sum*200);
	}
	return 0;
}