#include<stdio.h>  
#include<string.h>  
#include<algorithm>  
using namespace std;  
#define M 1000000  
char s[50100][20];  
struct  
{  
    int next[26];  
    int num;  
    void init()  
    {  
        num=0;  
        memset(next,0,sizeof(next));  
    }  
}root[M*4];  
int up;  
void insert(char *s)  
{  
    int i,p=0,id;  
    for(i=0;i<strlen(s);i++)  
    {  
        id=s[i]-'a';  
        if(root[p].next[id]==0)  
        {  
            root[p].next[id]=up;  
            root[up].init();  
            //root[p].num=1;  
            up++;  
            p=root[p].next[id];  
        }  
        else  
        {  
            p=root[p].next[id];  
        }  
    }  
    root[p].num=1;  
}  
int query(char *s,int a,int b)  
{  
    int i,p=0,id;  
    for(i=a;i<b;i++)  
    {  
        id=s[i]-'a';  
        if(root[p].next[id]==0)  
        return 0;  
        else  
        p=root[p].next[id];  
    }  
    if(root[p].num)  
    return 1;  
    else  
    return 0;  
}  
int main()  
{  
  up=1;  
  int i=0;  
  root[0].init();  
  while(scanf("%s",s[i])!=EOF)  
  {  
      insert(s[i]);  
      i++;  
  }  
  int j;  
  for(j=0;j<i;j++)  
  {  
      int l=strlen(s[j]);  
      for(int k=0;k<l-1;k++)//够暴力！  
      if(query(s[j],0,k)&&query(s[j],k,l))  
      {  
          printf("%s\n",s[j]);  
          break;  
      }  
  }  
  return 0;  
} 