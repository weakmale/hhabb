#include<iostream>
using namespace std;
int main()
{
	int t,i,r;
	double d,h,m,s;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>h>>m>>s;
		if(h>12)
				h=h-12;
		d=h*30.0+m/2.0+s/120.0-m*3.0-s/20.0;
		if(d<0)
			d=-1*d;
		if(d>180)
			d=360-d;
		r=d;
		cout<<r<<endl;
	}
}