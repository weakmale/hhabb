#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct node{
    string s;int a;int ans;
}pe[3010];
int peo[3010];
bool cmp(node a,node b){ return a.a<b.a; }
int main(){
    int n; scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>pe[i].s>>pe[i].a;
        pe[i].ans=0;
    }
    sort(pe+1,pe+1+n,cmp);
    int k=3000;
    for(int i=1;i<=n;i++){
        if(pe[i].a>=i){
            puts("-1");
            return 0;
        }
        pe[i].ans = i - pe[i].a+1;
        for(int j = 1;j<i;j++){
            if(pe[j].ans>=pe[i].ans)
                pe[j].ans++;
        }
    }
    for(int i=1;i<=n;i++)
        cout<<pe[i].s<<" "<<pe[i].ans<<endl;
    return 0;
}
