#include "cstdio"
#include "cstring"
#include "iostream"
using namespace std;
int a[310];
char M[310][310];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n; ++i )
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
        scanf("%s",M[i]);
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(M[i][j]=='0' && M[i][k]=='1' && M [j][k]=='1'){
                    M[i][j]='1';
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        int wei=i; int minn=a[i];
        for(int j=i;j<=n;j++){
            if(M[i][j]=='1'){
                if(minn>a[j])
                {
                    minn=a[j]; wei=j;
                }
            }
        }
        swap(a[i],a[wei]);
    }
    for(int i=0;i<n-1;i++)
        printf("%d ",a[i]);
    printf("%d\n",a[n-1]);
    return 0;
}