#include<cstdio>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n%3==0)
            printf("%d",n/3*2);
        else
            printf("%d\n",n/3*2+1);
    }
    return 0;
}