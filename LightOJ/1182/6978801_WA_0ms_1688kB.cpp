#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int main(){
	int T; scanf("%d",&T); int t=1;
	while(T--){
        int a; scanf("%d",&a);
        if(a&1)
            printf("Case %d: odd\n",t++);
        else
            printf("Case %d: even\n",t++);
	}

	return 0;
}
