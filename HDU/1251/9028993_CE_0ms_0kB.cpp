#include "cstdio"
#include "iostream"
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
Tire tire[100010];
void Build(string s){
    int now=0;
    for(int i=0;i<s.size();i++){
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
int queue(string s){
    int now=0;
    for(int i=0;i<s.size();i++){
        int c = s[i]-'a';
        int to = tire[now].next[c];
        if(to==-1) return 0;
        now  = to;
    }
    return tire[now].v;
}
int main(){
    tot=0;
    string s;
    while(cin>>s)
        Build(s);
    while(cin>>s)
        printf("%d\n",queue(s));
    return 0;
}