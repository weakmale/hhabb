#include<iostream>
using namespace std;
int main()
{
	int i,t,m,n,j;
	int sum=1;
	cin>>t;
	for(i=0;i<t;i++)
	{
		
		cin>>m>>n;
		sum=n;
		for(j=1;j<m;j++)
		{
			sum=sum*((n-j)/2.0);
		}
		sum=sum%1007;
		cout<<sum<<endl;
		
	}
	return 0;
}