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
char sr[50010][30];
int tot;
Tire tire[100010];
void Build(char s[]){
    int now=0;
    for(int i=0;s[i];i++){
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
int queue(char s[],int x,int y){
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
    while(scanf("%s",sr[++n])!=EOF)
        Build(sr[n]);
//    sort(sr+1,sr+1+n,cmp);
    for(int i=1;i<=n;i++){
        int l = (int)strlen(sr[i]);
        for(int j=0;j<l-1;j++){
            if(queue(sr[i], 0,j)&&queue(sr[i],j,l)){
                printf("%s\n",sr[i]);
                break;
            }
        }
    }
    return 0;
}
