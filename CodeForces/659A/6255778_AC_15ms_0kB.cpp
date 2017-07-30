#include<cstdio>
int main() {
    int n,a,b;
    while(scanf("%d%d%d",&n,&a,&b)!=EOF){
        if(b<0){
            while(b<0)  b=b+n;
            if(a+b>n)
                printf("%d\n",a+b-n);
            else
                printf("%d\n",a+b);
        }
        else{
            while(b>n) b=b-n;
            if(a+b>n)
                printf("%d\n",a+b-n);
            else
                printf("%d\n",a+b);
        }
    }
    return 0;
}