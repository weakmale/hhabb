#include<iostream>
#include <iomanip>
using namespace std;
int main()
{
	int t,n,m,j,i,a[500],k;
	float x,sum;
	cin>>t;
	for(i=0;i<t;i++)
	{
		sum=0.0;
		x=0.0;
		cin>>n;
		for(j=0;j<n;j++)
		{
			cin>>a[j];
			x++;
		}
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				if(a[j]>a[k])
					sum=sum+1;
			}
		}
		x=x*(x-1);
		sum=sum/x;
		cout <<setprecision(6)<<sum<<endl;
	}
	return 0;
}