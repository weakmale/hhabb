#include "cstdio"
#include "cstring"
char s[100010];
int sum[100010];
int lowbet(int x){
    return x&(-x);
}
void Sum(int x,int b,int n){
    while(x<=n){
        sum[x]+=b;
        x+=lowbet(x);
    }
}
int Q(int x){
    int summ=0;
    while(x>0){
        summ+=sum[x];
        x-=lowbet(x);
    }
    return summ;
}
int main(){
    int T; scanf("%d",&T); int kcase=1;
    while(T--){
        scanf("%s",s);
        int n=strlen(s);
        memset(sum,0,sizeof(sum));
        int m; scanf("%d",&m);
        printf("Case %d:\n",kcase++);
        while(m--){
            char c[3];
            scanf("%s",c);
            if(c[0]=='I'){
                int a,b; scanf("%d %d",&a,&b);
                Sum(a,1,n); Sum(b+1,-1,n);
            }
            else{
                int a; scanf("%d",&a);
                int summ=Q(a);
                if(summ%2){
                    if(s[a-1]=='0')
                        printf("1\n");
                    else
                        printf("0\n");
                }
                else{
                    printf("%c\n",s[a-1]);
                }
            }
        }
    }
    return 0;
}