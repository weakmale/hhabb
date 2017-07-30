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
    while(~scanf("%d %d",&n,&m)&&n&&m){
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
        int t=0;
        if(A) num[++t].s='A', num[t].v=A;
        if(C) num[++t].s='C', num[t].v=C;
        if(D) num[++t].s='D', num[t].v=D;
        if(E) num[++t].s='E', num[t].v=E;
        if(G) num[++t].s='G', num[t].v=G;
        sort(num+1, num+1+t, cmp);
        for(int i=1;i<t;i++)
            printf("%c %d ",num[i].s,num[i].v);
        printf("%c %d\n",num[t].s,num[t].v);
    }
    return 0;
}
