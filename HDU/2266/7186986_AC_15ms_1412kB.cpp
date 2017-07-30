#include<cstdio>
#include<cstring>
char s[20];
long long n;
long long sum;
int ans;
int ln;
int d[3]={0,1,2};
void DFS(int sum,int t){
    if(t==ln){
        if(sum==n)
           ans++;
        return ;
    }
    long long cnt=0;
    for(int i=t;i<ln;i++){
        cnt=cnt*10+(s[i]-'0');
        DFS(sum+cnt,i+1);
        if(t)
            DFS(sum-cnt,i+1);
    }
}
int main(){
    while(~scanf("%s %lld",s,&n)){
        ln=strlen(s);
        ans=0;
        DFS(0,0);
        printf("%d\n",ans);
    }

    return 0;
}
