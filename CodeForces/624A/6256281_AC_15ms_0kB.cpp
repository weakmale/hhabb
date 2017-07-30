
#include<cstdio>
int main(){
    double d,l,v1,v2;
    while(scanf("%lf%lf%lf%lf",&d,&l,&v1,&v2)!=EOF){
        double sum=v1+v2;
        l=l-d;
        printf("%.10lf\n",l/sum);
    }
    return 0;
}