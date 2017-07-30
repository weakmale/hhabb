#include<cstdio>
#include<cstring>
char map[300][300];
char s[100];
int n;
bool k;
int vis[300];
void DFS(char c){
	if(c=='m'){
		k=true;return;
	}
	for(int i=0;i<n;i++){
		if(map[i][0]==c&&vis[i]==false){
			vis[i]=true;
			DFS(map[i][1]);
			vis[i]=false;
		}
	}
}
int main(){
	while(scanf("%s",s)!=EOF)  
    {   
		k=false;
        n=0;  
        int len=strlen(s);  
        map[n][0]=s[0];  
        map[n][1]=s[len-1];  
        n++;  
		memset(vis,false,sizeof(vis));
		while(~scanf("%s",s)){
			if(s[0]=='0')
				break;
			else{
				len=strlen(s);
				map[n][0]=s[0];
				map[n++][1]=s[len-1];
				
			}
		}
		
		for(int i=0;i<n;i++)  
  	 	{  
   		     if(map[i][0]=='b')  
 	       {  
				vis[i]=1;  
    	        DFS(map[i][1]);  
   		     }  
      		  if(k)  
   		     	break;  
   			 }  
		if(k)
			printf("Yes.\n");
		else	
			printf("No.\n")	;
	}
	return 0;
}