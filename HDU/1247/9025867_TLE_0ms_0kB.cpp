#include "cstdio"
#include "cstring"
#include "algorithm"
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
bool cmp(string s1,string s2){ return s1<s2; }
void Build(string s){
    int now=0;
    for(int i=0;i<s.size();i++){
        int c = s[i]-'a';
        int Next = tire[now].next[c];
        if(Next==-1){
            Next=++tot;
            tire[Next].~Tire();
            tire[now].next[c]=Next;
        }
        now = Next;
    }
    tire[now].v=1;
}
int queue(string s,int x,int y){
    int now = 0;
    for(int i=x;i<y;i++){
        int c = s[i]-'a';
        int Next = tire[now].next[c];
        if(Next==-1)
            return 0;
        now = Next;
    }
    return tire[now].v;
}
int main(){
    int n=0;  tot=0;
    while(cin>>sr[++n])
        Build(sr[n]);
    //    sort(sr+1,sr+1+n,cmp);
    for(int i=1;i<=n;i++){
        for(int j=0;j<sr[i].size()-1;j++){
            if(queue(sr[i], 0,j)&&queue(sr[i],j,(int)sr[i].size())){
                cout<<sr[i]<<endl;break;
            }
        }
    }
    return 0;
}