#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int main(){
	int T;scanf("%d",&T); int t=1;
	while(T--){
        char s[100];
        scanf("%s",s);
		int len=strlen(s);
        bool K=false;
        for( int i=0;i<=len/2;i++){
            if(s[i]!=s[len-i-1])
                K=true;
        }
        printf("Case %d: ",t++);
        if(!K)
            printf("Yes\n");
        else
            printf("No\n");
	}

	return 0;
}
