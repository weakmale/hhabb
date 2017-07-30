#include "cstdio"
int a[110][110];
int b[110][110];
int main(){
    int n,m;    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]==0){
                for(int k=1;k<=m;k++)
                    b[i][k]=1;
                for(int k=1;k<=n;k++)
                    b[k][j]=1;
//                printf("%d %d\n",i,j);
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
        {
            if(b[i][j])
                b[i][j]=0;
            else
                b[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int sum=0;
            for(int k=1;k<=m;k++){
                sum=sum|b[i][k];
            }
            for(int k=1;k<=n;k++){
                sum=sum|b[k][j];
//                printf("%d %d~~~%d %d\n",sum,b[k][j],k,j);
            }
            if(sum!=a[i][j])
            {
//                printf("%d %d\n",i,j);
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j-1)
                printf(" %d",b[i][j]);
            else
                printf("%d",b[i][j]);
        }
        printf("\n");
    }
    return 0;
}