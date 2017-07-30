#include<cstdio>
#include<stack>
using namespace std;
char str[1000011];
int main(){
	scanf("%s",str);
	int i=0;
	stack<char>cnt;
	int cns=0;
	bool k=true;
	while(str[i]){
		if(str[i]=='['||str[i]=='('||str[i]=='{'||str[i]=='<'){
			cnt.push(str[i]);
		}
		if(str[i]==']'||str[i]==')'||str[i]=='}'||str[i]=='>'){
			if(cnt.empty()){
				k=false;
				break;
			}
			else{
				if( !( (str[i]==']'&&cnt.top()=='[') || (str[i]=='}'&&cnt.top()=='{')||(str[i]==')'&&cnt.top()=='(')||(str[i]=='>'&&cnt.top()=='<') ) )   
					cns++;
				cnt.pop();
			}
		}
		i++;
	}
	if(cnt.empty()&&k)
		printf("%d\n",cns);
	else
		printf("Impossible\n");
	return 0;
}