#include<iostream>
using namespace std;
int main()
{
    int n,max=0,min=0;
    cin>>n;
    max=n/7*2;
    min=max;
    n=n%7;
    if(n<=5)
    {
        if(n<=2)
            cout<<min<<' '<<max+n<<endl;
        else
            cout<<min<<' '<<max+2<<endl;
    }
    if(n>5)
        cout<<min+n-5<<' '<<max+2<<endl;
    return 0;
        
}