#include "cstdio"
using namespace std;
/* father[x]表示x的根节点 */
int father[50005];

/*
 rank[x]表示father[x]与x的关系
 rank[x] == 0 表示father[x]与x是同类
 rank[x] == 1 表示x吃father[x]
 rank[x] == 2 表示father[x]吃x
 */
int rank[50005];

/* 初始化集合 */
void Make_Set(int x)
{
    father[x] = x;
}

/* 查找x所在的集合 */
int Find_Set(int x)
{
    int t;
    if (father[x] == x) return x;
    t = father[x];
    father[x] = Find_Set(father[x]);
    /* 因为压缩时根节点改变，必须更新father[x]与x的关系 */
    rank[x] = (rank[t] + rank[x]) % 3;
    return father[x];
}

/* 合并a和b */
void Union_Set(int a, int b, int len)
{
    int ra = Find_Set(a);
    int rb = Find_Set(b);
    /* 将集合ra合并到集合rb上 */
    father[ra] = rb;
    /* 更新father[ra]与ra的关系 */
    rank[ra] = (rank[b] - rank[a] + 3 + len) % 3 ;
}

int main()
{
    int i, n, m;
    int d, x, y;
    int rx, ry;
    int sum = 0;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
    {
        Make_Set(i);
    }
    while(m--)
    {
        scanf("%d%d%d", &d, &x, &y);
        if (x > n || y > n || (d == 2 && x == y))
        {
            sum++;
        }
        else
        {
            /* 求出x和y所在的集合rx和ry */
            rx = Find_Set(x);
            ry = Find_Set(y);
            /* 若在同一个集合则可确定x和y的关系 */
            if (rx == ry)
            {
                if((rank[x] - rank[y] + 3) % 3 != d - 1)
                {
                    sum++;
                }
            }
            /* 无法确定关系时按照规则合并节点 */
            else
            {
                Union_Set(x, y, d - 1);
            }
        }
    }
    printf("%d\n", sum);
    return 0;	
}