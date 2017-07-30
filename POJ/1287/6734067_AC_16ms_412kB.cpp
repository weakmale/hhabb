#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int per[1050],n;
struct node
{
    int a,b;
    int dis;
}x[5005];
bool cmp(node a,node b)
{
    return a.dis<b.dis;
}
void init()
{
    for(int i=1;i<=n;++i)
    {
        per[i]=i;
    }
}
int find(int x)
{
    int r=x;
    while(r!=per[r])
    {
        r=per[r];
    }
    int i=x,j;
    while(i!=r)
    {
        j=per[i];
        per[i]=r;
        i=j;
    }
    return r;
}
bool join(int a,int b)
{
    int x=find(a),y=find(b);
    if(x!=y)
    {
        per[y]=x;
        return 1;
    }
    return 0;
}

int main()
{
    int a,b,c,m;
    while(scanf("%d",&n),n)
    {
        init();
        scanf("%d",&m);
        for(int i=0;i<m;++i)
        {
            scanf("%d%d%d",&a,&b,&c);
            x[i].a=a;x[i].b=b;x[i].dis=c;
        }
        sort(x,x+m,cmp);
        int sum=0,cnt=0;
        for(int i=0;cnt<n-1;++i)
        {
            if(join(x[i].a,x[i].b))
            {
                sum+=x[i].dis;
                ++cnt;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
