#include "cstdio"
#include "vector"
#include "map"
#include "cstring"
#include "algorithm"
#include "iostream"
using namespace std;
typedef long long LL;
LL shu(string s,int num){
    LL sum=0;
    string ss="";
    for(int i=0;i<s.size();i++)
        if(i==s.size()-num) continue;
        else ss+=s[i];
    for(int i=0;i<ss.size();i++)
        sum=sum*10+ss[i]-'0';
    return  sum;
}
LL shushu(string s,int num){
    LL sum=0;
    string ss="";
    for(int i=0;i<s.size();i++){
        if(i==s.size()-num) continue;
        if(i>s.size()-num)ss+='9';
        else ss+=s[i];
    }
    for(int i=0;i<ss.size();i++)
        sum=sum*10+ss[i]-'0';
    return  sum;
}
int main(){
    int T; scanf("%d",&T);
    int kcase=1;
    while(T--){
        string s1,s2;
        cin>>s1>>s2;
  //      LL num1 = shu(s1,30);//num2 = shu(s2, 30);
        LL t=1;LL k1=1;
        int i=1;
        LL k2=1;
        while(t<=shu(s1, i)){
//            printf("%lld\n",shu(s1,i));
            if(s1[s1.size()-i]=='0')
                k1=k1+shu(s1,i)-t+1;
            else k1=k1+shushu(s1,i)-t+1;
            t*=10;
            i++;
        }
        t=1,i=1;
        while(t<=shu(s2, i)){
//            printf("%lld\n",shu(s1,i));
            if(s2[s2.size()-i]=='0')
                k2=k2+shu(s2,i)-t+1;
            else k2=k2+shushu(s2,i)-t+1;
            t*=10;
            i++;
        }
        LL sum=k2-k1;
        for(int i=0;i<s1.size();i++)
            if(s1[i]=='0') sum++;
        printf("Case %d: %lld\n",kcase++,sum);
    }
    return 0;
}
