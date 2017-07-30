#include "cstdio"
#include "cstring"
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
string sr[50010];
int tot;
Tire tire[100010];
void Build(string s){
    int now=0;
    for(int i=0;i<s.size();i++){
        int c = s[i]-'a';
        int Next = tire[now].next[c];
        if(Next==-1){
            Next=++tot;
            tire[now].next[c]=Next;
        }
        now = Next;
    }
    tire[now].v=1;
}
int queue(string s,int x){
    int now = 0;
    for(int i=x;i<s.size();i++){
        int c = s[i]-'a';
        int Next = tire[now].next[c];
        if(Next==-1)
            return 0;
        now = Next;
        if(tire[now].v==1) return i;
    }
    return 0;
}
int main(){
    int n=0;
    while(cin>>sr[++n])
        Build(sr[n]);
    for(int i=1;i<=n;i++){
        int num1 = queue(sr[i], 0);
        if(num1+1 == sr[i].size()) continue;
        num1 = queue(sr[i],num1+1);
        if(num1+1==sr[i].size()) cout<<sr[i]<<endl;
    }
}
