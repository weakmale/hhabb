#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
struct node{
    int num;
    int jibie;
    bool friend operator <(node a, node b)
    {
        if(a.jibie==b.jibie)  return a.num>b.num;  
        else return a.jibie<b.jibie;  
    }
}pa;
int T;

char str[10];
int main(){
    while(~scanf("%d",&T)){
    int k=0;
    priority_queue<node> q[4];
    while(T--){
        int doc;
        scanf("%s%d",str,&doc);  
        if(strcmp(str,"IN")==0)   
        {  
            scanf("%d",&pa.jibie);  
            pa.num=++k;  
            q[doc].push(pa);  
              
        }else  
        {  
            if(q[doc].empty()) printf("EMPTY\n");  
            else {  
                pa=q[doc].top();  
                printf("%d\n",pa.num);  
                q[doc].pop();  
            }
        }
    }
}
    return 0;
}