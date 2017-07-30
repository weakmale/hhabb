#include<cstdio>
#include<cstring>
int map[300][300];
char s[100];
int n;
bool k=false;
int vis[300][300];
void DFS(char c){
	for(int i=0;i<n;i++){
		if(map[i][0]==c&&vis[i][0]==false){
			if(k) break;
			if(map[i][1]=='m'){
				k=true;
			}
			else{
				char x=c;
				c=map[i][1];
				vis[i][0]=true;
				DFS(c);
				vis[i][0]=false;
				c=x;
				
			}
		}
		
	}
}
int main(){
	n=0;
	int x;
	memset(vis,false,sizeof(vis));
	while(~scanf("%s",s)){
		if(s[0]=='0')
			break;
		else{
			int z=strlen(s);
			map[n][0]=s[0];
			map[n++][1]=s[z-1];
			
		}
	}
	k=false;
	DFS('b');
	if(k)
		printf("Yes.\n");
	else	
		printf("No.\n")	;
	return 0;
}