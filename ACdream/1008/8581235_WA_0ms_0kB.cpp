#include "cstdio"
#include "algorithm"
#include "vector"
#include "iostream"
using namespace std;
bool vis1[100010];
bool vis2[100010];
int main(){
    printf("%d\n",5%3);
    string s; cin>>s;
    string ss = "";
    int K=0;
    int i=0;
    int sum=0;
    int sum1=0;
    int sum2=0;
    while(i<s.size()){
        if(s[i]=='0') K=1;
        if((s[i]-'0')%3==1)sum1++,vis1[i]=true;
        if((s[i]-'0')%3==2)sum2++,vis2[i]=true;
        sum = sum+s[i]-'0';i++;
    }
    int k = sum%3;
    if(sum<3){
        if(K) puts("0");
        else puts("-1");
        return 0;
    }
    if(k==0){
        int i=0;
        while(s[i]=='0'&&i<s.size()) i++;
        if(i==s.size()) puts("0");
        while(i<s.size()){
            cout<<s[i];i++;
        }
    }
    else if(k==1){
        if(sum1==0) puts("-1");
        else{
            
            
        }
    }
    return 0;
}
