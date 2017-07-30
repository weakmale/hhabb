#include "cstdio"
int W[22][22][22];
int main(){
    for(int a=0;a<=20;a++){
        for(int b=0;b<=20;b++){
            for(int c=0;c<=20;c++){
                if( a <= 0 || b <= 0 || c <= 0)
                    W[a][b][c]=1;
                else if( a < b && b < c )
                    W[a][b][c]=W[a][b][c-1]+W[a][b-1][c-1]-W[a][b-1][c];
                else
                    W[a][b][c]=W[a-1][b][c]+W[a-1][b-1][c] + W[a-1][b][c-1] - W[a-1][b-1][c-1];
            }
        }
    }
    int a,b,c;
    while(scanf("%d %d %d",&a,&b,&c),a!=-1||b!=-1||c!=-1){
        printf("w(%d, %d, %d) = ",a,b,c);
        if( a <= 0 || b <= 0 || c <= 0)
            printf("%d\n",W[0][0][0]);
        else if( a > 20 || b > 20 || c > 20)
            printf("%d\n",W[20][20][20]);
        else
            printf("%d\n",W[a][b][c]);
    }
    return 0;
}