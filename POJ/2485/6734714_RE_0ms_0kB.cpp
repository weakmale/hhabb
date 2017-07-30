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
    int T;
    scanf("%d",&T);
    while(T--)
    {	scanf("%d",&n);
        init();
        int t=0;
        for(int i=1;i<=n;++i)
        {
        	for(int j=1;j<=n;j++){
            	scanf("%d",&c);
            	x[t].a=i; x[t].b=j; x[t].dis=c; t++;
            }
        }
        sort(x,x+t,cmp);
        int sum=0,cnt=0;
        for(int i=0;cnt<n-1;++i)
        {
        	
            if( join(x[i].a,x[i].b) )
            {
                if(x[i].dis>sum)
                	sum=x[i].dis;
				
                ++cnt;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
