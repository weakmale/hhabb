#include<cstdio>
int main()
{
    int n,max=0,s=0;
    while(scanf("%d",&n)!=EOF)
    {
        int b[n];
        for(int i=0;i<n;i++){
            scanf("%d",&b[i]);}
        max=0;int sum=0;
        for(int i=0;i<n;i++)
        {
            s=0;
            if(b[i])
            {
                int k=b[i];
                for(int j=0;j<n;j++)
                {
                    if(b[j]==k)
                    {
                        s++;
                        b[j]=0;
                    }
                }
            }
            if(s>max)
                max=s;
            sum+=s;
        }
        printf("%d\n",sum-max);
    }
    return 0;
}