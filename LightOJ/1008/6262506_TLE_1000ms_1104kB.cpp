#include<cstdio>
#include<cmath>
int main(){
    int T,i;scanf("%d",&T);
    for(i=1;i<=T;i++){
        long long j,s,sum=0,x=1,y=1;
        double m;
        scanf("%lld",&s);m=sqrt(s)*10;j=m;
        if(j%10)
            j=sqrt(s)+1;
        else
            j=sqrt(s);
        sum=j*j;
        if(j%2==0){
            x=j;y=1;
            long long k=1;
            while(k<j&&sum>s){
                sum--;k++;y++;
            }
            k=1;
            while(k<j&&sum>s){
                sum--;x--;k++;
            }
        }
        else{
            x=1;y=j;
            long long k=1;
            while(k<j&&sum>s){
                sum--;x++;k++;
            }
            k=1;
            while(k<j&&sum>s){
                sum--;y--;k++;
            }
        }
        printf("Case %d: %lld %lld\n",i,x,y);
    }
    return 0;
}