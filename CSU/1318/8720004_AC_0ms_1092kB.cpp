#include<cstdio>
typedef long long LL;
int main()
{
    int n;
    //scanf("%d",&n);
    while(scanf("%d",&n) != EOF){
        LL sum = 0,nl = 1,num = 0;
        while(sum < n){
            sum += nl;
            nl = sum + 1;
            num++;
        }
        printf("%lld\n",num);
    }
    return 0;
}
