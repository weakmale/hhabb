#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    int Mis=max(3*a/10,a-a/250*c);
    int Vas=max(3*b/10,b-b/250*d);
    if(Mis>Vas)
        printf("Misha\n");
    else if(Mis<Vas)
        printf("Vasya\n");
    else
        printf("Tie\n");
    return 0;
}
