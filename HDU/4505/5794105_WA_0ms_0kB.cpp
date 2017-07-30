#include<iostream>
using namespace std;
int main()
{
	int c,n,i=0,j=0,k=0,a[15],b=0,t=0;
	cin>>c;
	for(i=0;i<c;i++)
	{
		cin>>n;t=0;
		for(j=0;j<n;j++)
		{
			cin>>a[j];
			for(k=0;k<j;k++)
			{
				if(a[k]==a[j])
				{
					b=0;
					break;
				}
					else
						b=1;
			}
			if(b==1)
				t=t+5;
			if(a[j]>a[0])
				a[0]=a[j];
		}
		t=t+n+a[0]*6+a[0]*4;
		cout<<t<<endl;
		}
}
