#include "cstdio"
using namespace std;
int main(){
    int n; scanf("%d",&n);
    puts("INTERSECTING LINES OUTPUT");
    while(n--){
        double x1,x2,x3,x4;
        double y1,y2,y3,y4;
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
        double k1,k2;
        double b1,b2;
        if(x1-x2==0){
            if(x3-x4==0)
                if(x1==x3) puts("LINE");
                else puts("NONE");
            else{
                k2 = (y3-y4)/(x3-x4);
                b2 = y3 - k2*x3;
                double xi = x1;
                double yi = k2*xi+b2;
                printf("POINT %.2lf %.2lf\n",xi,yi);
            }
        }
        else if(x3-x4==0){
            k1 = (y1-y2)/(x1-x2);
            b1 = y1 - k1*x1;
            double xi = x3;
            double yi = k1*xi+b1;
            printf("POINT %.2lf %.2lf\n",xi,yi);
        }
        else{
            k1 = (y1-y2)/(x1-x2);
            k2 = (y3-y4)/(x3-x4);
            b1 = y1 - k1*x1;
            b2 = y3 - k2*x3;
//            printf("%lf %lf %lf %lf\n",k1,k2,b1,b2);
            if(k1==k2&&b1==b2)
                puts("LINE");
            else if(k1==k2&&b1!=b2)
                puts("NONE");
            else{
                double xi = (b2-b1)/(k1-k2);
                double yi = k1*xi+b1;
                printf("POINT %.2lf %.2lf\n",xi,yi);
            }
        }
    }
    puts("END OF OUTPUT");
    return 0;
}