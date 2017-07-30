#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int main(){
	int n; int a,b,c,d;
	 int x=-1,y,k;
	scanf("%d",&n);
	for(int i=1;i<=4;i++){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        int minn=min(a,b);
        int minn2=min(c,d);
        if(n-minn>=minn2)
                 x=minn, y=n-minn,k=i;
	}
	if(x==-1)
        printf("-1\n");
    else
        printf("%d %d %d",k,x,y);
	return 0;
}
