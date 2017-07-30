#include<cstdio>
int main()
{
    int t; scanf("%d",&t);
    while(t--)
    {
        char a[100000];
        int i=0,sum=0;
        scanf("%s",a);
        while(a[i])
        {
            if(a[i]>='0'&&a[i]<='9')
                sum++;
            i++;
        }
        printf("%d\n",sum);
    }
    return 0;
}