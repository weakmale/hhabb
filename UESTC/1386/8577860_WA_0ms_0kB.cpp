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
//    printf("%d %d %d~~~\n",t,l,r);
    int i=l,j=0;
    while(i<r){
//        printf("%d %d %d %d\n",t,i,j,r);
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
//        printf("~~~%d\n",j);
        int num=0;
        while(j!=-1){
            if(KMP(j+1,j+1,k-j-1)){ num = j+1; break;}
            j = Next[j];
        }
        printf("%d\n",num);
    }
    return 0;
}