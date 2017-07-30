#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
double K,L,S,W;
const double G=9.81;
int main(){
	while(scanf("%lf %lf %lf %lf",&K,&L,&S,&W),K,L,S,W){
        if(L>S){
            int V=sqrt(2*G*S);
            if(V>10)
                printf("Killed by the impact.\n");
            else
                printf("James Bond survives.\n");
            continue;
        }
        int f=G*W;
        double dl=S-L;
        double V=2*G*L;
        double a=(dl*K/2-f)/W;
        V=V-2*a*dl;
 //       printf("%lf~~~~~\n",V);
        if(sqrt(V)>10)
            printf("Killed by the impact.\n");
        else if(V<0)
            printf("Stuck in the air.\n");
        else{
            printf("James Bond survives.\n");
        }
	}
	return 0;
}
