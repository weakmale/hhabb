#include<cstdio>
int main()
{
    char x,y,z;
    while(scanf("%c%c%c",&x,&y,&z)!=EOF)
    {
        char c;
        if(x>y)
        {
            c=x;
            x=y;
            y=c;
        }
        else if(x>z)
        {
            c=x;
            x=z;
            z=c;
        }
        if(y>z)
        {
            c=y;
            y=z;
            z=c;
        }
        printf("%c %c %c\n",x,y,z);
    }
    return 0;
}