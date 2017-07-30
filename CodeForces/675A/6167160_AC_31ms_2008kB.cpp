#include<cstdio>
int main()
{
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        int t=b-a;
        if(c==0)
        {
            if(a==b)
                printf("YES\n");
            else
                printf("NO\n");
        }
        else {if( t%c==0 &&((t>=0 && c>0) ||( t<=0 &&c <0)))
            printf("YES\n");
        else
            printf("NO\n");}
    }
    return 0;
}