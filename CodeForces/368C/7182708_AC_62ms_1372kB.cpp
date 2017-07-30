#include "cstdio"
#include "cmath"
#include "iostream"
using namespace std;

char s[100010];
int x[100010];
int y[100010];
int z[100010];
int main(){
    scanf("%s",s);
    if(s[0]=='x')
        x[0]=1;
    if(s[0]=='y')
        y[0]=1;
    if(s[0]=='z')
        z[0]=1;
    for(int i=1;s[i];i++){
        if(s[i]=='x')
            x[i]=x[i-1]+1;
        else
            x[i]=x[i-1];
        if(s[i]=='y')
            y[i]=y[i-1]+1;
        else
            y[i]=y[i-1];
        if(s[i]=='z')
            z[i]=z[i-1]+1;
        else
            z[i]=z[i-1];
    }
    int n; scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int l,r; scanf("%d %d",&l,&r);
        l--; r--;
        if(r-l+1<3){
            printf("YES\n");
            continue;
        }
        int xi=x[r]-x[l];
        int yi=y[r]-y[l];
        int zi=z[r]-z[l];
        if(s[l]=='x')
            xi++;
        if(s[l]=='y')
            yi++;
        if(s[l]=='z')
            zi++;
        if(abs(xi-yi)<=1&&abs(xi-zi)<=1&&abs(yi-zi)<=1)
            printf("YES\n");
        else
            printf("NO\n");
            
    }
    return 0;
}
