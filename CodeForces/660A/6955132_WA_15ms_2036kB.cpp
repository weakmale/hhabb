#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
int a[1010];
int GCD(int a,int b){
    if(b==0)
        return a;
    return GCD(b,a%b);
}
int main(){
    int n;int x;
    scanf("%d",&n);
    int k=1;
    scanf("%d",&a[1]);
    for(int i=2;i<=n;i++){
        scanf("%d",&x);
        if(GCD(x,a[k])==1)
            a[++k]=x;
        else{
            int j=min(a[k]+1,x+1);
            while(GCD(j,x)!=1||GCD(a[k],j)!=1)
                j++;
            a[++k]=j;
            a[++k]=x;
        }
    }
    printf("%d\n",k-n);
    for(int i=1;i<k;i++)
        printf("%d ",a[i]);
    printf("%d\n",a[k]);
	return 0;
}