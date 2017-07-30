#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
int n;
int k;
int main(){
	int T; scanf("%d",&T);
	while(T--){
        scanf("%d %d",&n,&k);
        if(k>n)
            printf("0\n");
        else{
            int r = n%k;
            if(r<k/2)
                printf("%d\n",n*n-r*r);
            else{
                printf("%d\n",n*n-(k-r)*(k-r));
            }
        }
	}
	return 0;
}
