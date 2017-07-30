#include "cstdio"
const int MAXX=1e6+10;
bool su[MAXX];
int biao[MAXX];
int a,b,k;
bool judge(int mid){
    for(int i=a;i<=b-mid+1;i++)
        if(biao[mid+i-1]-biao[i-1]<k) return true;
    return false;
}
int main(){
    scanf("%d %d %d",&a,&b,&k);
    for(int i=2;i<=b;i++){
        biao[i]=biao[i-1];
        if(su[i])
            continue;
        biao[i]++;
        for(int j=i+i;j<=b;j+=i)
            su[j]=true;
    }
    int l=0,r=b-a+1;
    int ans=r;
    while(l<=r){
        int mid=(r+l)>>1;
        if(judge(mid)){  l=mid+1;
        }
        else r=mid-1,ans=mid;
    }
    if(judge(ans)) ans=-1;
    printf("%d\n",ans);
    return 0;
}