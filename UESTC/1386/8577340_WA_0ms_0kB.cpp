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
    while(i<s.size()-1){
        if(j==-1||s[i]==s[j]) Next[++i]=++j;
        else j = Next[j];
    }
}
bool KMP(int t,int l,int r){
    int i=l,j=0;
    while(i<r){
        if(j==-1||s[j]==s[i])
            i++,j++;
        else j=Next[j];
        if(j==t) return true;
    }
    return false;
}
int main(){
    int n; scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>s; Getnext();
        string sq=""; string sh="";
        int k = (int)s.size();
        int j = Next[k-1];
        while(j>0&&k/(j+1)<3){
            j = Next[j];
        }
        int num=-1;
        while(j>0){
            if(KMP(j,j+1,k-j-1)){ num = j; break;}
            j = Next[j];
        }
        printf("%d\n",num+1);
    }
    return 0;
}