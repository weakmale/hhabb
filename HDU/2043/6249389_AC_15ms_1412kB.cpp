#include<cstdio>
int main()
{
    int m; scanf("%d",&m);;
    while(m--)
    {
        char str[51];
        scanf("%s",str);
        int i=0,k=0,j=0,l=0,n=0,sum=0;
        while(str[i]){
            if(str[i]>='A'&&str[i]<='Z')
                if(k==0)
                    k++;
            if(str[i]>='a'&&str[i]<='z')
                if(j==0)
                    j++;
            if(str[i]>='0'&&str[i]<='9')
                if(l==0)
                    l++;
            if(str[i]=='@'||str[i]=='~'||str[i]=='!'||str[i]=='#'||str[i]=='$'||str[i]=='%'||str[i]=='^')
                if(n==0)
                    n++;
            i++;
        }
        sum=k+j+l+n;
        if((i>=8&&i<=16)&&(sum>2))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}