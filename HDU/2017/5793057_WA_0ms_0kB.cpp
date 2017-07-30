#include<iostream>
using namespace std;
int main()
{
	int n,i,j,g=0;
	char a[100000];
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a;
		j=0;g=0;
		while(a[j]!='\n')
		{
			if(a[j]<58&&a[j]>46)
				g=g+1;
			j++;
		}
		cout<<g<<endl;
	}
	return 0;
}