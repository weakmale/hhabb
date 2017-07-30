#include "cstdio"
#include "vector"
#include "map"
#include "cstring"
#include "algorithm"
using namespace std;
map<long long,bool>Map;
int main(){
    int n;
    while(~scanf("%d",&n)){
        if(n&(n-1)) puts("YES");
        else puts("NO");
    }
    return 0;
}