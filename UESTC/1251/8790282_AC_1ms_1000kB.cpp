#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int T; scanf("%d",&T);
	int n,s;
	while(T--){
		scanf("%d %d",&n,&s);
		if(n==1&&s==0){
			puts("0 0"); continue;
		}
		string s1="1",s2="";
		for(int i=1;i<n;i++)
			s1+='0';
		int sum=0;
		for(int i=1;i<=n;i++){
			if(sum<s){
				if(s-sum>=9)
					s2+='9',sum+=9;
				else{
				 	s2=s2+char(s-sum+'0');
				 	sum=sum+(s-sum);
				}
			}
			else s2=s2+'0';
		}
		if(sum!=s){
			puts("-1 -1");continue;
		}
		sum=1;
		for(int i=n-1;i>=0;i--){
			if(sum<s){
				if(s-sum>=9){
					s1[i]='9';
					if(i==0) 
						sum+=8;
					else
						sum+=9;
				}
				else{ 
					s1[i]=char((s1[i]-'0'+(s-sum+'0')));
					sum=sum+(s-sum);
				}
			}
		}
		if(sum!=s){
			puts("-1 -1");continue;
		}
		cout<<s1<<" "<<s2<<endl;
	}
	return 0;
}
