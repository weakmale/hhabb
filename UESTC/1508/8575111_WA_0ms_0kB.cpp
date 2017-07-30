#include "cstdio"
#include "cmath"
#include "algorithm"
using namespace std;
const double EXP = 1e-8;
double L(double x1,double y1,double x2,double y2){
    return sqrt(pow((x1-x2),2.0)+pow((y1-y2),2.0));
}
int main(){
    int n; scanf("%d",&n);
    if(n==1){
        double a,b; scanf("%lf %lf",&a,&b);
        printf("%.4lf %.4lf %.4lf",0.0,a,b);
    }
    else if(n==2){
        double x1,x2,y1,y2; scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
        printf("%.4lf %.4lf %.4lf",L(x1,y1,x2,y2)/2,(x1+x2)/2,(y1+y2)/2);
    }
    else{
        double x1,x2,y1,y2,x3,y3;
        scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3);
        double l1 = L(x1,y1,x2,y2)/2;
        double l2 = L(x1,y1,x3,y3)/2;
        double l3 = L(x2,y2,x3,y3)/2;
        double l=l1;
        if(l-l2<=EXP) l=l2;
        if(l-l3<EXP) l=l3;
        double xi = (x1+x2+x3)/3, yi = (y1+y2+y3);
        double lt = L(xi,yi,x1,y1);
        if(lt-l<EXP) printf("%.4lf %.4lf %.4lf",lt,xi,yi);
        else{
            if(l1-l2>=EXP&&l1-l3>=EXP) printf("%.4lf %.4lf %.4lf",l1,(x1+x2)/2,(y1+y2)/2);
            else if(l2-l1>=EXP&&l2-l3>=EXP) printf("%.4lf %.4lf %.4lf",l2,(x1+x3)/2,(y1+y3)/2);
            else if(l3-l1>=EXP&&l3-l2>=EXP) printf("%.4lf %.4lf %.4lf",l3,(x3+x2)/2,(y3+y2)/2);
        }
    }
    puts("");
    return 0;
}