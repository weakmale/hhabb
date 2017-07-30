#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
const int MAXX=5e4+10;
int c[MAXX];
int n;
int lowbit(int x){
    return x&(-x);
}
void add(int x, int d) {
    while(x <= n) {
        c[x] += d;
        x += lowbit(x);
    }
}
int sum(int a) {
    int s = 0;
    while(a > 0) {
        s += c[a];
        a -= lowbit(a);
    }
    return s;
}
int main(){
	int T; scanf("%d",&T); int kcase=1;
	while(T--){
        memset(c,0,sizeof(c));
        scanf("%d",&n); int a,b;
        for(int i=1;i<=n;i++){
            scanf("%d",&a);
            add(i,a);
        }
        char str[20];
        printf("Case %d:\n",kcase++);
        while(scanf("%s", str), str[0] != 'E') {
            int x, y;
            scanf("%d%d", &x, &y);
            if(str[0] == 'A') {
                add(x, y);
            }
            else if(str[0] == 'S') {
                add(x, -y);
            }
            else {
                printf("%d\n", sum(y) - sum(x-1));
            }
        }
	}
	return 0;
}