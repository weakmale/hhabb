#include<iostream>
using namespace std;
int  shu(int i,int m,int n,int sum)
{
	int j;
	for(i++;i<=n;i++)
	{
		if(i>=(n-m+1))
		{
			for(j=i;j<=n;j++)
			{	sum=sum+1;}
		}
		else
			sum=shu(i,m,n,sum);
		
	}
	return sum;
}

int main()
{
	int i,t,m,n,j,k;
	int sum=0;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cin>>m>>n;
		j=0;
		sum=0;
		sum=shu(j,n,m,sum);
		cout<<sum<<endl;
	}
	return 0;
}