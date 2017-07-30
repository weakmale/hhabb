#include "cstdio"
#include "cstring"
#include "algorithm"
using namespace std;
char s[1010];
struct node {
    char s; int v;
}num[10];
bool cmp(node a,node b){
    if(a.v==b.v) return a.s<b.s;
    return a.v>b.v;
}
int main(){
    int n,m;
    while(scanf("%d %d",&n,&m),n||m){
        int A=0,C=0,D=0,E=0,G=0;
        for(int i=1;i<=n;i++){
            scanf("%s",s+1);
            for(int i=1;i<=m;i++){
                if(s[i]=='A') A++;
                if(s[i]=='C') C++;
                if(s[i]=='D') D++;
                if(s[i]=='E') E++;
                if(s[i]=='G') G++;
            }
        }
        num[1].s='A'; num[1].v=A;
        num[2].s='C'; num[2].v=C;
        num[3].s='D'; num[3].v=D;
        num[4].s='E'; num[4].v=E;
        num[5].s='G'; num[5].v=G;
        sort(num+1, num+6, cmp);
        for(int i=1;i<=4;i++)
            printf("%c %d ",num[i].s,num[i].v);
        printf("%c %d\n",num[5].s,num[5].v);
    }
    return 0;
}