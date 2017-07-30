#include<cstdio>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int a[n+1],b=0,x=0,i=0;
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        b=a[0]=0; i=0;
        while(b<=15)
        {
            b=a[i+1]-a[i];
            i++;
        }
        x=a[i-1];
        if(x+15>90)
            printf("90\n");
        else
            printf("%d\n",x+15);
    }
    return 0;
}