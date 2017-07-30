#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
int y[1010];
struct node{
    int sum; int num;
}a[1010];
bool cmp(node x ,node y){
    if(x.sum!=y.sum)
        return x.sum<y.sum;
    else
        return x.num>y.num;
}
int main(){
    for(int i=1;i<=1010;i++){
        a[i].num=i;  a[i].sum=0;
        for(int j=1;j<=i;j++)
            if(i%j==0)
                a[i].sum++;
    }
    sort(a+1,a+1000+1,cmp);
	int T;int t=1; scanf("%d",&T);
	while(T--){
        int n;  scanf("%d",&n);
        printf("Case %d: %d\n",t++,a[n].num);
	}
	return 0;
}
