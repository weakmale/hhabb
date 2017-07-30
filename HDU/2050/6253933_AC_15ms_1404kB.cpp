
#include<cstdio>
int main()
{
    int C;scanf("%d",&C);
    while(C--){
        int n;  scanf("%d",&n);int t=1;
        for(int i=1;i<=n;i++){
            t=t+4*(i-1)+1;
        }
        printf("%d\n",t);
    }
    return 0;
}