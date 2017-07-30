#include "cstdio"
#include "map"
#include "iostream"
using namespace std;
struct Tire{
    int next[10];
    int v;
    void init(){
        memset(next, -1, sizeof(next));
        v=0;
    }
};
Tire tire[100010];
int tot,maxx;
void insert(char s[]){
    int i=0,now=0; int ln = (int)strlen(s);
    while(s[i]=='0'&&i<ln-1)
        i++;
    for(;i<ln;i++){
        int c = s[i]-'0';
        int to = tire[now].next[c];
        if(to==-1){
            to = ++tot;
            tire[now].next[c]=to;
            tire[to].init();
        }
        now = to;
    }
    tire[now].v++;
    maxx = max(maxx,tire[now].v);
}
char s[50];
int main(){
    int n;
    while(~scanf("%d",&n)){
        tot=0; tire[0].init(); maxx=0;
        while(n--)
            scanf("%s",s),insert(s);
        printf("%d\n",maxx);
    }
    return 0;
}