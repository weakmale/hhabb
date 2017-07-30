#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
int a,b;
int ans[10020];
int  judge(int x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0)
            return 0;
    }
    return 1;
}
int main(){
    for(int i=0;i<=10005;i++){
        ans[i]=judge(i*i+i+41);
    }
	while(scanf("%d %d",&a,&b)!=EOF){
        int k=0;
        for(int i=a;i<=b;i++){
                k+=ans[i];
        }
        printf("%.2f\n",k*1.0/(b-a+1)*100+1e-8);
	}
	return 0;
}