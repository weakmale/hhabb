#include "cstdio"
#include "iostream"
#include "cstring"
using namespace std;
struct Tire{
    int next[26];
    int v;
    Tire(){
        memset(next, -1, sizeof(next));
        v=0;
    }
};
int tot;
char s[100];
Tire tire[500010];
void Build(char s[]){
    int now=0;
    for(int i=0;i<s[i];i++){
        int c = s[i]-'a';
        int to = tire[now].next[c];
        if(to==-1){
            to = ++tot;
            tire[to].~Tire();
            tire[now].next[c]=to;
        }
        now = to;tire[now].v++;
    }
}
int queue(char s[]){
    int now=0;
    for(int i=0;i<s[i];i++){
        int c = s[i]-'a';
        int to = tire[now].next[c];
        if(to==-1) return 0;
        now  = to;
    }
    return tire[now].v;
}
int main(){
    tot=0;
    while(~scanf("%s",s))
        Build(s);
    while(~scanf("%s",s))
        printf("%d\n",queue(s));
    return 0;
}