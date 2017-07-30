#include <cstdio>
int main(){
    int n;
    scanf("%d",&n);
    char s[1010][10]; int  K=1;
    for(int i=0;i<n;i++){
        scanf("%s",s[i]);
        if(s[i][0]=='O'&&s[i][1]=='O'&&K){
            s[i][0]='+';
            s[i][1]='+';
            K=0;
        }
        else if(s[i][3]=='O'&&s[i][4]=='O'&&K)
        {
            K=0; s[i][3]='+'; s[i][4]='+';
        }
    }
    if(K)
        printf("NO\n");
    else{
        printf("YES\n");
        for(int i=0;i<n;i++)
            printf("%s\n",s[i]);
    }
    return 0;
}
