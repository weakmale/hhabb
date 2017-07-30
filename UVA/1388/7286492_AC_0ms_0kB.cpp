#include "cstdio"
#include "algorithm"
using namespace std;
const double L=10000;
double a[10000];
int main(){
    double n,m;
    while(~scanf("%lf %lf",&n,&m)){
        double len=L/n;
        double bian=L/(n+m);
        int k=1;
        
        double sum=0;
        for(int i=1;i<n+m;i++){
            if(i*bian<k*len&&(i+1)*bian>=len*k){
                sum+=min((k*len-i*bian),((i+1)*bian-k*len));
                if((i*bian-k*len)>((i+1)*bian-k*len)) i++;
                k++;
            }
//            printf("%lf %lf\n",k*len,i*bian);
        }
        printf("%.4lf\n",sum);
    }
    return 0;
}