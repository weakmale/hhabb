#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXX=1010;
int n;
int m;
int F[MAXX];
struct node{
	int x;
	int y;
	int vi;
}ega[MAXX*5];
bool cmp(node a,node b){
	return a.vi<b.vi;
}
void init()
{
    for(int i=1;i<=n;++i)
    {
        F[i]=i;
    }
}
int Found(int x)
{
    int r=x;
    while(r!=F[r])
    {
        r=F[r];
    }
    int i=x,j;
    while(i!=r)
    {
        j=F[i];
        F[i]=r;
        i=j;
    }
    return r;
}
bool Union(int a,int b)
{
    int x=Found(a),y=Found(b);
    if(x!=y)
    {
        F[y]=x;
        return 1;
    }
    return 0;
}
int main(){
  	int a,b,c,m;
    while(scanf("%d",&n),n)
    {
        init();
        scanf("%d",&m);
        for(int i=0;i<m;++i)
        {
            scanf("%d%d%d",&a,&b,&c);
            ega[i].x=a;ega[i].y=b;ega[i].vi=c;
        }
		sort(ega,ega+m,cmp);
		int cnt=0;int sum=0;
        for(int i=0;cnt<n-1;++i)
        {	
            if(Union(ega[i].x,ega[i].y))
            {
                sum+=ega[i].vi;
                ++cnt;
            }
        }
        printf("%d\n",sum);
	}
	return 0;
}