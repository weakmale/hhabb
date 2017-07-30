#include<iostream>
using namespace std;
int main()
{
    int n,max=0,min=0;
    cin>>n;
    max=n/7;
    min=max;
    n=n%7;
    if(n<=5)
        cout<<min<<' '<<max+n<<endl;
    if(n>5)
        cout<<min+n-5<<' '<<max+2<<endl;
    return 0;
        
}