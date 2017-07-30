#include<cstdio>
int main()
{
    char a[3],d;
    while(scanf("%s",a)!=EOF)
    {
        if(a[0]>a[1])
        {
            d=a[0];
            a[0]=a[1];
            a[1]=d;
        }
        if(a[0]>a[2])
        {
            d=a[0];
            a[0]=a[2];
            a[2]=d;
        }
        if(a[1]>a[2])
        {
            d=a[1];
            a[1]=a[2];
            a[2]=d;
        }
        printf("%c %c %c\n",a[0],a[1],a[2]);
    }
    return 0;
}