#include "cstdio"
#include "iostream"
#include "cstring"
using namespace std;
string s;
int Next[100010];
void Getnext(){
    memset(Next, 0, sizeof(Next));
    int j=-1,i=0;
    Next[0]=-1;
    while(i<s.size()){
        if(j==-1||s[i]==s[j]) Next[++i]=++j;
        else j = Next[j];
    }
}
bool KMP(string ss,int l,int r){
    int i=l,j=0;
    while(i<r){
        if(j==-1||ss[j]==s[i])
            i++,j++;
        else j=Next[j];
        if(j==ss.size()) return true;
    }
    return false;
}
int main(){
    int n; scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>s; Getnext();
        string sq=""; string sh="";
        int k = (int)s.size();
        int j=0;
        int num=0;
        sq = sq+s[j++]; sh = s[--k]+sh;
        while(sq==sh&&j<k){
            if(k-j+1<sq.size()) break;
            if(KMP(sq,j,k)) num = (int)sq.size();
            else break;
            sq = sq +s[j++]; sh = s[--k]+sh;
        }
        printf("%d\n",num);
    }
    return 0;
}