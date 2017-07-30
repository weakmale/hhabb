#include "cstdio"
#include "iostream"
using namespace std;
struct node {
    int vi;
    int num[11];
    node(){
        vi=0;
        for(int i=0;i<=10;i++) num[i]=-1;
    }
};
int dp[3][66];
int tot;
int n;
node tire[4000000];
void build(int y){
    
    int x = y%3;
    int now=0;
    for(int i=n,j=0;i>=1&&j<=40;i--,j++){
        int t = dp[x][i];
        int next = tire[now].num[t];
        if(next==-1){
            next = ++tot;
            tire[next].~node();
            tire[now].num[t]=next;
            tire[next].vi=y;
        }
        now = next;
    }
}
int queue(string s){
    int k=-1;
    int now=0;
    for(int i=0;i<s.size();i++){
        int t = s[i]-'0';
        int next = tire[now].num[t];
        if(next==-1) return -1;
        now = next;
        k = tire[now].vi;
    }
    return k;
}
void  Add(int x,int y,int z){
    for(int i=1;i<=55;i++) dp[z][i]=0;
    for(int i=1;i<=n;i++){
        if((dp[x][i]+dp[y][i]+dp[z][i])>=10){
            dp[z][i+1]=dp[z][i+1]+1;
            if(i+1>n) n++;
        }
        dp[z][i]=(dp[x][i]+dp[y][i]+dp[z][i])%10;
    }
    if(n>50){
        for(int i=1;i<=50;i++)
            dp[y][i]=dp[y][i+1],dp[x][i]=dp[x][i+1];
        for(int i=1;i<n;i++)
            dp[z][i]=dp[z][i+1];
        n--;
    }
}
int main(){
    tire[0].~node();
    n=1; dp[0][1]=1; dp[1][1]=1;
    build(0);  build(1);
    for(int i=2;i<100000;i++){
        Add( (i-2)%3, (i-1)%3, i%3);
//        for(int j=n;j>=1;j--)
//            printf("%d",dp[i%3][j]);
//        printf("  %d  %d\n",i,n);
        build(i);
    }
//    printf("%d\n",tot);
    int T,kcase=0;
    scanf("%d",&T);
    while(T--){
        string s; cin>>s;
        printf("Case #%d: %d\n",++kcase,queue(s));
    }
    return 0;
}

    
