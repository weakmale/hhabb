#include "cstdio"
#include "algorithm"
using namespace std;
struct node{
    int x,id;
};
node a[100010];
node b[100010];
bool cmp(node a,node b){
    return a.x<b.x;
}
bool cmp1(node a,node b){
    return a.id<b.id;
}
int main(){
    int n; scanf("%d",&n);
    int k=n/3;
    if(n%3) k++;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i].x),a[i].id=i;
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=k;i++){
        b[i].x=0; b[i].id=a[i].id;
        b[i+k].x=a[i+k].x; b[i+k].id=a[i+k].id;
        b[i+2*k].x=k-i; b[i+2*k].id=a[i+2*k].id;
    }
    sort(a+1,a+1+n,cmp1); sort(b+1,b+1+n,cmp1);
    printf("YES\n");
    for(int i=1;i<=n;i++)
        printf("%d ",a[i].x-b[i].x);
    printf("\n");
    for(int i=1;i<=n;i++)
        printf("%d ",b[i].x);
}