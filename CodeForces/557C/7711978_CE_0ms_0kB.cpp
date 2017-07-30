#include "cstdio"
#include "algorithm"
using namespace std;
const int Maxx = 1e5;
struct node{
    int ln,vi;
}cha[Maxx+10];
int sum[210];
bool cmp(node a,node b){ return a.ln>b.ln; }
int main(){
    memset(sum, 0, sizeof(sum));
    int n; scanf("%d",&n);
    int Sum=0;
    for(int i=1;i<=n;i++) scanf("%d",&cha[i].ln);
    for(int i=1;i<=n;i++) scanf("%d",&cha[i].vi),sum[cha[i].vi]++,Sum+=cha[i].vi;
    sort(cha+1, cha+1+n, cmp);
    int cnt = 1;int s = cha[1].vi; int ss=0;
    for(int i=2;i<=n+1;i++){
        if(cha[i].ln==cha[i-1].ln){
            cnt++; s+=cha[i].vi; sum[cha[i].vi]--;
        }
        else{
            for(int j=200;j>0&&cnt>1;j--){
                if(sum[j] <= cnt-1) s += sum[j]*j, cnt -= sum[j];
                else {s += (cnt-1)*j, cnt = 1;}
                if(cnt<=1) break;
            }
            ss = max(ss,s);
            cnt=1;s = cha[i].vi; sum[cha[i].vi]--;
        }
    }
    printf("%d\n",Sum-ss);
    return 0;
}