#include<iostream>
using namespace std;
int sanjiao(int a[40][40])
{
	int i,j;
	a[1][1]=1;
	a[2][1]=1;
	a[2][2]=1;
	for(i=3;i<40;i++)
	{
		a[i][1]=1;a[i][i]=1;
		for(j=2;j<i;j++)
			a[i][j]=a[i-1][j-1]+a[i-1][j];
	}
}
int main()
{
	int i,j,k,t,n,a[40][40];
	sanjiao(a);
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n;
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=j;k++)
			cout<<a[j][k]<<' ';
			cout<<endl;
		}
	}
	return 0;
}