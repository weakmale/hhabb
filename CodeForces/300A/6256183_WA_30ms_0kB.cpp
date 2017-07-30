#include<cstdio>
#include <algorithm>
using namespace std;
int main( ){
    int n;
    while(scanf("%d",&n)!=EOF){
        int a[n],xiao=0,da=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            if(a[i]<0)
                xiao++;
            if(a[i]>0)
                da++;
        }
        sort(a,a+n);
        if(xiao%2==0){
            if(a[n-1]>0){
                printf("1 %d\n",a[0]);
                printf("%d",da);
                for(int i=xiao+1;i<n;i++)
                    printf(" %d",a[i]);
                printf("\n");
                printf("%d 0",xiao);
                for(int i=1;i<xiao;i++)
                    printf(" %d",a[i]);
                printf("\n");
            }
            else{
                printf("1 %d",a[0]);
                printf("%d",xiao-2);
                for(int i=2;i<xiao;i++)
                    printf(" %d",a[i]);
                printf("\n");
                printf("2 0 %d\n",a[1]);
                
            }
        }
        else{
            if(a[n-1]>0){
                printf("1 %d\n",a[0]);
                printf("%d",da);
                for(int i=xiao+1;i<n;i++)
                    printf(" %d",a[i]);
                printf("\n");
                printf("%d 0",xiao);
                for(int i=1;i<xiao;i++)
                    printf(" %d",a[i]);
                printf("\n");
            }
            else{
                printf("1 %d\n",a[0]);
                printf("%d",n-2);
                for(int i=1;i<xiao;i++)
                    printf(" %d",a[i]);
                printf("\n");
                printf("1 0\n");
            }
        }
    }
    return 0;
}