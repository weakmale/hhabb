#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
int a,b;
int ans[1010];
int  judge(int x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0)
            return 0;
    }
    return 1;
}
int main(){
    for(int i=0;i<=1005;i++){
        ans[i]=judge(i*i+i+41);
    }
	while(scanf("%d %d",&a,&b)!=EOF){
        int t=0;
        for(int i=a;i<=b;i++){
                t+=ans[i];
        }
        printf("%.2lf\n",t*1.0/(b-a+1)*100);
	}
	return 0;
}
