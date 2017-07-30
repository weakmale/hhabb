#include "cstdio"
#include "cmath"
#include "iostream"
using namespace std;
const double PI=acos(-1.0);
int main(){
    int n; scanf("%d",&n);
    double maxx=0; double minn=2*PI;
    while(n--){
        double x,y;
        scanf("%lf %lf",&x,&y);
        if(x==0&&y==0)
            continue;
        if(x==0&&y>0){
            maxx=max(PI/2,maxx);
            minn=min(PI/2,minn);
        }
        else if(x==0&&y<0){
            maxx=max(PI/2*3,maxx);
            minn=min(PI/2*3,minn);
        }
        else{
            maxx=max(atan(y/x),maxx);
            minn=min(atan(y/x),minn);
        }
//        printf("%lf %lf\n",maxx,minn);
    }
    printf("%lf\n",(maxx-minn)/PI*180);
    return 0;
}