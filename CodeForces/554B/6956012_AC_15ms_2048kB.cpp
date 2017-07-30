#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
char s[110][110];
int main(){
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    int maxx=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<n;j++)
            if(strcmp(s[i],s[j])==0)
                sum++;
        maxx=max(maxx,sum);
    }
	printf("%d\n",maxx);
	return 0;
}
