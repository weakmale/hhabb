#include "cstdio"
#include "map"
#include "vector"
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
int tot,k;
int du[100010];
Tire tire[100010];
int F[250010];
int Found(int x){ return F[x]==x?x:F[x]=Found(F[x]); }
void Union(int x,int y){
    x = Found(x); y=Found(y);
    if(x!=y) F[y]=x;
}
int index(char s[]){
    int now=0;
    for(int i=0;s[i];i++){
        int c = s[i]-'a';
        int Next = tire[now].next[c];
        if(Next==-1){
            Next = ++tot;
            tire[Next].~Tire();
            tire[now].next[c]=Next;
        }
        now = Next;
    }
    if(tire[now].v==0) tire[now].v=++k;
    du[tire[now].v]++;
    return tire[now].v;
}
char s1[20];
char s2[20];
int head;
int main(){
    for(int i=0;i<=250000;i++) F[i]=i;
    tot=0;k=0;
    int i=1;
    while(~scanf("%s %s",s1,s2)){
        int a=index(s1),b=index(s2);
        Union(a, b); i++;
    }
    int ans=0;
    for(int i=1;i<=k;i++){
        if(Found(i)!=Found(1)){
            puts("Impossible");return 0;
        }
    }
    for(int i=1;i<=k;i++) if(du[i]&1) ans++;
    if(ans==0||ans==2) puts("Possible");
    else puts("Impossible");
    return 0;
}