#include "cstdio"
#include "iostream"
#include "cstring"
#include "cmath"
using namespace std;
char s[100010];
char s1[100010];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    scanf("%s",s);
    for(int i=n-1,j=0;i>=0;i--,j++)
        s1[i]=s[j];
    if(m>n/2)
        m=n-m+1;
//    printf("%d\n",m);
    int time=0;int k=0;
    int ke=n/2+n%2;
    int r=0, l=0;
    int r1=0;
    int l1=0;
    for(int i=m-1;i>=0;i--){
        if(s[i]!=s1[i])
            l=i,l1++;
    }
    l=m-1-l;
    for(int i=m-1;i<ke;i++){
        if(s[i]!=s1[i])
            r=i,r1++;
    }
    r=r-m+1;
    if(s[m-1]!=s1[m-1])
        r++,l++;
//    printf("%d %d\n",r,l);
    if(l<r)
        k=1;
    if(l<=0)
        k=0;
    if(r<=0)
        k=1;
//    printf("%s\n%s\n",s,s1);
    while(true){
        int t=0; int rr=0;
        if(strcmp(s1, s)==0)
            break;
        if(k){
            for(int i=m-1;i>=0;i--){
                if(s1[i]!=s[i]){
                    rr=i+1;
                    break;
                }
                t++;
            }
//            printf("m=%d\n",m);
            l1--;
            if(l1<=0)
                k=0;
        }
        else{

            for(int i=m-1;i<ke;i++){
                if(s1[i]!=s[i]){
                    rr=i+1;
                    break;
                }
                t++;
            }
            r1--;
            if(r1<=0)
                k=1;
        }
        m=rr; time+=t;
//       printf("%s %s\n",s,s1);
//       printf("%d %d\n",t,m);
        t=abs(s1[m-1]-s[m-1]);
        t=min(26-t,t);
        time+=t;
        s1[m-1]=s[m-1];
        s1[n-m]=s1[m-1];
        s[n-m]=s[m-1];
//        printf("%s %s %d\n\n",s,s1,t);
    }
    printf("%d\n",time);
    return 0;
}