#include "cstdio"
#include "cstring"
#include "cmath"
#include "algorithm"
#include "vector"
using namespace std;
//double  vi[40010];
vector<double>G;
int t;
double a,b,c,L,R;
struct node{
    double x,y;
}id[40010];
int sgn(double x)
{
    if(x>1e-8) return 1;
    if(x<-1e-8) return -1;
    return 0;
}
//double jie1(double A,double B,double C){
//    return (-B+sqrt(B*B-4*A*C))/(2*A);
//}
//double jie2(double A,double  B,double C){
//    return (-B-sqrt(B*B-4*A*C))/(2*A);
//}
double func(double x)
{
    return a*x*x+b*x+c;
}
void judge(node p,node q)
{
    
    if(sgn(p.x-q.x)==0)
    {
        double y=func(p.x);
        if(p.y>q.y) swap(p,q);
        if(sgn(y-p.y)>0&&sgn(y-q.y)<0) G.push_back(p.x);
        return;
    }
    
    double k=(q.y-p.y)/(q.x-p.x);
    double A=a;
    double B=b-k;
    double C=c+k*p.x-p.y;
    double temp=B*B-4*A*C;
//    printf("%lf %lf %lf %lf\n",k,A,B,C);
    if(sgn(temp)<=0) return;
    temp=sqrt(temp);
    double x1=(-B-temp)/(2*A);
    double x2=(-B+temp)/(2*A);
    if(p.x>q.x) swap(p,q);
    if(sgn(x1-p.x)>0&&sgn(x1-q.x)<0)
        G.push_back(x1);
    if(sgn(x2-p.x)>0&&sgn(x2-q.x)<0)
        G.push_back(x2);
}
void judge2(node p1,node p,node p2)
{
    if(sgn(func(p.x)-p.y)) return;
    p1.x=p.x+(p1.x-p.x)*1e-3;
    p1.y=p.y+(p1.y-p.y)*1e-3;
    p2.x=p.x+(p2.x-p.x)*1e-3;
    p2.y=p.y+(p2.y-p.y)*1e-3;
    if(sgn(func(p1.x)-p1.y)*sgn(func(p2.x)-p2.y)==-1)
    {
 //       vi[++t]=p.x;
        G.push_back(p.x);
    }
}
double cal(double x)
{
    double A=4*a*a;
    double B=4*a*b;
    double C=b*b+1;
    double temp=A*x*x+B*x+C;
    return (2*A*x+B)/(4*A)*sqrt(temp)+(4*A*C-B*B)/(8*A*sqrt(A))*log(fabs(2*A*x+B+2*sqrt(A)*sqrt(temp)));
}

double jifen(double l,double r)
{
    if(l<L) l=L;
    if(r>R) r=R;
    if(l>=r) return 0;
    return cal(r)-cal(l);
}
int main(){
    int n;
    while(~scanf("%d %lf %lf %lf %lf %lf",&n,&a,&b,&c,&L,&R)){
        G.clear();
        for(int i=1;i<=n;i++){
            scanf("%lf %lf",&id[i].x,&id[i].y);
        }
        id[0]=id[n];
        id[n+1]=id[1];
        for(int i=1;i<=n;i++){
            judge(id[i], id[i+1]);
        }
        for(int i=1;i<=n;i++)
            judge2(id[i-1],id[i],id[i+1]);
        sort(G.begin(),G.end());
        double sum=0;
        for(int i=0;i<G.size();i+=2){
            sum+=jifen(G[i],G[i+1]);
//            printf("%lf\n",G[i]);
        }
        printf("%.2lf\n",sum);
    }
    return 0;
}