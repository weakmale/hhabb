#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct node{
    int s;
    char t[20];
    int sco;
    int i;
}a[111];
bool cmp(node a,node b){
    if(a.s!=b.s)
        return a.s>b.s;
    else 
        return strcmp(a.t,b.t)<0;
}
bool cmp1(node a,node b){
    return a.i<b.i;
}
int N;
int main(){
    while(scanf("%d", &N) == 1 && N > 0){
        int c[6]={0};
        for(int i=0;i<N;i++){
            scanf("%d %s",&a[i].s,a[i].t);
            a[i].i=i;
            c[a[i].s]++;
        }
        sort(a,a+N,cmp);
        for(int i=1;i<5;i++){
            if(c[i]==1)
                continue;
            c[i]/=2;
        }
        for(int i=0;i<N;i++){
            if(a[i].s==5)
                a[i].sco=100;
            else if(a[i].s==0)
                a[i].sco=50;
            else{
                int k=1;
                int l=a[i].s;
                while(a[i].s==l&&i<N){ 
                    if(k<=c[l])
                        a[i].sco=100-(5-l)*10+5;
                    else
                        a[i].sco=100-(5-l)*10;
                    k++;i++;
                }
                i--;
            }
        }
        sort(a,a+N,cmp1);
        for(int i=0;i<N;i++)
            printf("%d\n",a[i].sco);
        printf("\n");
    }
    return 0;
}