#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    int n,t=0; while(scanf("%d",&n)!=EOF){
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++){
        t=0;
        for(int j=0;j<n;j++){
            if(j!=i){
                if((fabs(a[i]-a[j])<=2)&&a[i]!=a[j])
                    for(int k=0;k<n;k++){
                        if( k!=i && k!=j ){
                            if( (fabs(a[k]-a[i])<=2)   && (fabs(a[k]-a[j])<=2)     &&          a[k]!=a[i]    &&     a[k]!=a[j]){
                                t=1; break;
                            }
                        }
                    }
            }
            if(t) break;
        }
        if(t)
            break;
    }
    if(t)
        printf("YES\n");
    else
        printf("NO\n");
    }
    return 0;
}