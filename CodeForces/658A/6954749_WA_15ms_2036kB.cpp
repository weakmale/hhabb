#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
int a[100];
int b[100];
int main(){
	int n,c;
	int L=0; int P=0;
	scanf("%d %d",&n,&c); int sum=0;
	for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
	for(int i=1;i<=n;i++){
        sum+=b[i];
        L+=max(a[i]-sum*c,0);

	}
	sum=0;
	for( int i=n;i>=1;i--){
        sum+=b[i];
        P+=max(a[i]-sum*c,0);
	}
 //   printf("%d %d\n",L,P);
	if(L>P)
        printf("Limak\n");
    else if(P>L)
        printf("Radewoosh\n");
    else
        printf("Tid\n");
	return 0;
}
