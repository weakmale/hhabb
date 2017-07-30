#include "cstdio"
#include "cstring"
#include "iostream"
using namespace std;
struct Tire{
    int next[2];
    int v;
    Tire(){
        memset(next, -1, sizeof(next));
        v=0;
    }
};
int tot;
int K;
Tire tire[100010];
void insert(string s){
    int now=0;
    for(int i=0;i<s.size();i++){
        int c = s[i]-'0';
        int to = tire[now].next[c];
        if(to==-1){
            to = ++tot;
            tire[to].~Tire();
            tire[now].next[c]=to;
        }
        now = to;
        if(tire[now].v) K=1;
    }
    tire[now].v=1;
    if(tire[now].next[0]!=-1||tire[now].next[1]!=-1) K=1;
}
int main(){
    string sr;
    int kcase=0;
    while(cin>>sr){
        K=false;tot=0; tire[0].~Tire();
        if(sr[0]==9){
            printf("Set %d is immediately decodable\n",++kcase);
            continue;
        }
        insert(sr);
        while(cin>>sr&&sr[0]!='9')
            insert(sr);
        if(!K) printf("Set %d is immediately decodable\n",++kcase);
        else printf("Set %d is not immediately decodable\n",++kcase);
    }
    return 0;
}
