#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int T;
	int x,y,x1,x2,y1,y2;
	int a1,a2,b1,b2;
	scanf("%d",&T);
	while(T--){
        scanf("%d %d",&x,&y);
        scanf("%d %d %d %d",&a1,&b1,&a2,&b2);
        if(x < a1 || x > a2 || y < b1 || y > b2)
            printf("Outside\n");
        else if(x == a1 || x == a2 || y == b1 || y == b2)
            printf("On\n");
        else printf("Inside\n");
	}
	return 0;
}
