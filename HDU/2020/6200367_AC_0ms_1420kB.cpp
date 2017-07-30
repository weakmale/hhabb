
#include<cstdio>
int main( )
{
    int n;
    while(scanf("%d",&n)&&n!=0)
    {
        int a[100],b[100]={0},max,k,c;
        for(int i=0;i<n;i++)
        {   scanf("%d",&a[i]); if(a[i]<0){a[i]=-a[i]; b[i]=1;}}
        for(int i=0;i<n;i++)
        {
            max=a[i];
            k=i;
            for(int j=i+1;j<n;j++)
            {
                if(a[j]>max)
                {
                    k=j;
                    max=a[j];
                }
            }
            if(k!=i)
            {
                if(b[k]!=b[i])
                {
                    c=b[k];
                    b[k]=b[i];
                    b[i]=c;
                }
                c=a[k];
                a[k]=a[i];
                a[i]=c;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i)
                printf(" ");
            if(b[i])
                printf("%d",-a[i]);
            else
                printf("%d",a[i]);
        }
        printf("\n");
    }
    return 0;
}