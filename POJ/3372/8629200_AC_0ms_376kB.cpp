#include "cstdio"
#include "vector"
#include "map"
#include "cstring"
#include "algorithm"
using namespace std;
int main(){
    int n;
    while(~scanf("%d",&n)){
        if(n&(n-1)) puts("NO");
        else puts("YES");
    }
    return 0;
}