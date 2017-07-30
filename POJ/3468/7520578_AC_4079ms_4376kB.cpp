#include <stdio.h>
#include <string.h>
#include <iostream>
#define BigInteger long long
using namespace std;
const int Max=100000;
struct nodenode
{
    BigInteger sum,val;
} node[Max<<2];
void PushUp(int tr)
{
    node[tr].sum=node[tr<<1].sum+node[tr<<1|1].sum;
}
void PushDown(int tr,int m)
{
    if(node[tr].val)
    {
        node[tr<<1].val+=node[tr].val;
        node[tr<<1|1].val+=node[tr].val;
        node[tr<<1].sum+=(BigInteger)(m-(m>>1))*node[tr].val;
        node[tr<<1|1].sum+=(BigInteger)(m>>1)*node[tr].val;
        node[tr].val=0;
    }
}
void Build(int l,int r,int tr)
{
    node[tr].val=0;
    if(l==r)
    {
        scanf("%I64d",&node[tr].sum);
        return ;
    }
    int m=(l+r)>>1;
    Build(l,m,tr<<1);
    Build(m+1,r,tr<<1|1);
    PushUp(tr);
}
BigInteger query(int L,int R,int l,int r,int tr)
{
    if(L<=l&&r<=R)
    {
        return node[tr].sum;
    }
    int m=(l+r)>>1;
    PushDown(tr,r-l+1);
    BigInteger ans=0;
    if(L<=m)ans+=query(L,R,l,m,tr<<1);
    if(m<R)ans+=query(L,R,m+1,r,tr<<1|1);
    PushUp(tr);
    return ans;
}
void Update(int L,int R,int add,int l,int r,int tr)
{
    if(L<=l&&r<=R)
    {
        node[tr].sum+=(BigInteger)add*(r-l+1);
        node[tr].val+=add;
        return ;
    }
    PushDown(tr,r-l+1);
    int m=(l+r)>>1;
    if(L<=m)Update(L,R,add,l,m,tr<<1);
    if(m<R)Update(L,R,add,m+1,r,tr<<1|1);
    PushUp(tr);
}
int main()
{
    int n,q,a,b;
    BigInteger c;
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        Build(1,n,1);
        char s[3];
        while(q--)
        {
            scanf("%s",s);
            if(s[0]=='Q')
            {
                cin >>a>>b;
                cout <<query(a,b,1,n,1)<<endl;
            }
            else if(s[0]=='C')
            {
                cin >>a>>b>>c;
                Update(a,b,c,1,n,1);
            }
        }
    }
    return 0;
}