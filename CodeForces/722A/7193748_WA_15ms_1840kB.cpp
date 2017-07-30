#include "cstdio"
char s[40];
int main(){
    int n; scanf("%d",&n);
    scanf("%s",s);
    if(n==24){
        if(s[0]>'2')
            s[0]='0';
        if(s[0]=='2'){
            if(s[1]>4)
                s[1]='0';
        }
        else{
            if(s[1]>'9')
                s[1]='0';
        }
        if(s[3]>'5')
            s[3]='0';
        printf("%s\n",s);
    }
    else{
        if(s[0]>'1'){
            s[0]='0';
        }
        if(s[0]=='1'){
            if(s[1]>'2')
                s[1]='0';
        }
        else{
            if(s[1]=='0')
                s[1]='1';
        }
        if(s[3]>'5')
            s[3]='0';
        printf("%s\n",s);
    }
    return 0;
}