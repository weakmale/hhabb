/*
POJ 2912
枚举+并查集
枚举每一个裁判，看有没有不出错的
如果没有，说明是Impossible
如果有超过一个，那么就是Can not determine
如果只有一个，那么输出其他出错的位置的最大值
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN=510;
const int MAXM=2010;
struct Node
{
    int u,v;
    int re;
}node[MAXM];
int F[MAXN];
int val[MAXN];
int find(int x)
{
    if(F[x]==-1)return x;
    int tmp=find(F[x]);
    val[x]+=val[F[x]];
    val[x]%=3;
    return F[x]=tmp;
}
char str[30];
int main()
{
    int n,m;
    int u,v;
    while(scanf("%d%d",&n,&m)==2)
    {
        gets(str);
        for(int i=0;i<m;i++)
        {
            //scanf("%s",&str);
            gets(str);
            int t=0;
            int len=strlen(str);
            for(t=0;t<len;t++)
              if(str[t]=='>'||str[t]=='='||str[t]=='<')
                break;
            u=0;
            for(int j=0;j<t;j++)
            {
                u*=10;
                u+=str[j]-'0';
            }
            v=0;
            for(int j=t+1;j<len;j++)
            {
                v*=10;
                v+=str[j]-'0';
            }
            node[i].u=u;
            node[i].v=v;
            if(str[t]=='=')node[i].re=0;
            else if(str[t]=='<')node[i].re=1;
            else node[i].re=2;
        }
        int ansi;
        int anst=0;
        int t0=0;//不矛盾的个数
        for(int i=0;i<n;i++)
        {
            memset(F,-1,sizeof(F));
            memset(val,0,sizeof(val));
            int ff=-1;
            for(int j=0;j<m;j++)
            {
                if(node[j].u==i || node[j].v==i)continue;
                u=node[j].u;
                v=node[j].v;
                int t1=find(u);
                int t2=find(v);
                if(t1==t2)
                {
                    if(val[v]!=(val[u]+node[j].re)%3)
                    {
                        ff=j+1;
                        break;
                    }
                }
                else
                {
                    F[t2]=t1;
                    val[t2]=val[u]-val[v]+node[j].re;
                    val[t2]=(val[t2]+3)%3;
                }
            }
            if(ff==-1)
            {
                ansi=i;
                t0++;
            }
            else anst=max(anst,ff);
        }
        if(t0==0)printf("Impossible\n");
        else if(t0>=2)printf("Can not determine\n");
        else
           printf("Player %d can be determined to be the judge after %d lines\n",ansi,anst);
    }
    return 0;
}