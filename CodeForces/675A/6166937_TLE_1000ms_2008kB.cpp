#include<cstdio>
int main()
{
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        long long t=0;
        t=a;
        if( ( ( b>a ) && ( c<0||c==0 ) ) || ( ( b<a ) && (c>0 || c==0) ) )
            printf("NO\n");
        else
        {
            if(c>0||c==0)
            {
                while(t<b&&t!=b)
                    t+=c;
                if(t==b)
                    printf("YES\n");
                else
                    printf("NO\n");
            }
            else
            {
                while(t>b&&t!=b)
                    t+=c;
                if(t==b)
                    printf("YES\n");
                else
                    printf("NO\n");
            }
        }
    }
    return 0;
}