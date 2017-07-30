#include <cstdio>
#include <cstring>
char s[1000010];
int next[1000010];
int main(){
    while(scanf("%s",s),s[0]!='.'){
        int len=strlen(s);
        int i=0,j=-1;
        next[0]=-1;
        while(i<len){
            if(j==-1||s[i]==s[j])
                i++,j++,next[i]=j;
            else j=next[j];
        }
        printf("%d\n",len/(len-next[len]));
    }
    return 0;
}
