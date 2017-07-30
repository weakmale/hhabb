#include "cstdio"
#include "cmath"
#include "iostream"
#include "algorithm"
using namespace std;
const double PI=acos(-1.0);
double jiao[100010];
int main(){
    int n; scanf("%d",&n);
    double maxx=0;
    for(int i=1;i<=n;i++){
        double x,y;
        scanf("%lf %lf",&x,&y);
        if(x==0&&y==0){
            jiao[i]=0;
            continue;
        }
        if(x==0&&y>0){
            jiao[i]=PI/2;
        }
        else if(x==0&&y<0){
            jiao[i]=PI/2*3;
        }
        else{
            if(x<0&&y>0){
                jiao[i]=PI-atan(y/-x);
            }
            else if(x<0&&y<=0){
                jiao[i]=PI+atan(-y/-x);
            }
            else if(x>0&&y<0){
                jiao[i]=2*PI-atan(-y/x);
            }
            else{
                jiao[i]=atan(y/x);
            }
        }
//        printf("%.10lf\n",jiao[i]/PI*180);
    }
    sort(jiao+1, jiao+1+n );
    jiao[n+1]=jiao[1];
    maxx=2*PI-(jiao[n]-jiao[1]);
    for(int i=1;i<n;i++){
        maxx=max(maxx,jiao[i+1]-jiao[i]);
    }
    printf("%.10lf\n",360-maxx/PI*180);
    return 0;
}