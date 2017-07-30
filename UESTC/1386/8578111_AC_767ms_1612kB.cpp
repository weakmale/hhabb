#include "cstdio"
#include "iostream"
#include "cstring"
using namespace std;
string s;
int Next[100010];
void Getnext(){
//    memset(Next, 0, sizeof(Next));
    int j=-1,i=0;
    Next[0]=-1;
    while(i<s.size()){
        if(j==-1||s[i]==s[j]) Next[++i]=++j;
        else j = Next[j];
    }
}
bool KMP(int x,int r){
//    printf("%d %d %d~~~\n",t,l,r);
    int i=x,j=0;
    while(j<r&&i<r){
//        printf("%d %d %d %d\n",t,i,j,r);
        if(j==-1||s[j]==s[i])
            i++,j++;
        else j=Next[j];
        if(j==x) return true;
    }
    return false;
}
int main(){
    int n; scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>s; Getnext();
        int k = (int)s.size();
        int j = Next[k];
//        printf("~~~%d\n",j);
        while(j){
            if(3*j>k) {j=Next[j];continue;}
            if(KMP(j,k)){ break;}
            j = Next[j];
        }
        printf("%d\n",j);
    }
    return 0;
}