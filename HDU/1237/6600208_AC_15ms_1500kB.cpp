#include<cstdio>
#include<stack>
using namespace std;
int main(){
	stack<double>cnt;
	double  a;
	while (scanf("%lf",&a) != EOF)
    {
        cnt.push(a);
        char c = getchar();
        if (a == 0 && c == '\n')
        {
            break;
        }
        char o;
        double b;
        while(1){
        	scanf("%c %lf",&o,&a);
        	if(o=='+'){
        		cnt.push(a);
        	}
        	else if(o=='-'){
        		a=-a;
        		cnt.push(a);
        	}
			else if(o=='*'){
        		b=cnt.top();
        		cnt.pop();
        		b*=a;
        		cnt.push(b);
			}
			else if(o=='/'){
        		b=cnt.top();
        		cnt.pop();
        		b/=a;
        		cnt.push(b);
			}
			
			if (getchar() == '\n')
            {
                break;
            }
			
		}
		double sum=0;
		while(!cnt.empty()){
			a=cnt.top();
			sum+=a;
			cnt.pop();
			
		}
        printf("%.2lf\n",sum);
    }
    return 0;
}