#include<cstdio>
#include<stack>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
stack<char>S;
char s[100010];
int main(){
	int T; scanf("%d",&T);
	while(T--){
		while(!S.empty()) S.pop();
		scanf("%s",s+1);
		int n = strlen(s+1);
		int num=1;
		int maxx=0;
		for(int i=1;i<=n;i++,num++){
			if(S.empty()){	
				num=1;
				if(s[i]==')'){
					maxx = i;
					break;
				}
				else
					S.push(s[i]);
			}
			else if(s[i]=='(')
				S.push(s[i]);
			else if(s[i]==')'){
				if(!S.empty())
					S.pop();
				else{
					maxx = i;
					break;
				}
			}
		}
		if(maxx==0) maxx = num-1;
		printf("%d\n",maxx);
	}
}