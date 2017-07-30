#include "cstdio"
#include "iostream"
#include "algorithm"
#include "string"
using namespace std;
int main(){
    string str;
    while(cin>>str,str[0]!='.'){
        int len=int (str.size());
        for(int i=1;i<=len;i++){
            if(len%i==0){
                string st="";
                string st1=str.substr(0,i);
                int k=len/i;
                for(int i=1;i<=k;i++)
                    st+=st1;
                if(st==str){
                    printf("%d\n",k);
                    break;
                }
            }
        }
    }
    return 0;
}
