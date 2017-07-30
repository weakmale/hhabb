#include<cstdio>  
#include<cstring>  
#include<algorithm>  
using namespace std;  
struct Node  
{  
    char name[30];  
    char sex[10];  
    double r1,r2;  
    double score;  
 }a[110];  
 int cmp1(Node a,Node b)  
 {  
    return a.r1>b.r1;      
 }  
 int cmp2(Node a,Node b)  
 {  
    return a.r2>b.r2;  
 }  
 int cmp3(Node a,Node b)  
 {  
    return a.score >b.score;   
  }   
int main()  
{  
    int t,n,m;  
    double m1,m2;   
    scanf("%d",&t);  
    while(t--)  
    {     
        int f=0;  
        int f1=0;
		int k;  
        scanf("%d%d",&n,&m);  
        if(!m)  
            continue;   
        for(int i=1;i<=n;i++)  
        {  
            scanf("%s %s %lf %lf",a[i].name,a[i].sex,&a[i].r1,&a[i].r2);
        }       
        sort(a+1,a+n+1,cmp1);  
        m1=300.0/a[1].r1;
        sort(a+1,a+n+1,cmp2);          
        m2=300.0/a[1].r2;   
        for(int i=1;i<=n;i++)          
            a[i].score=0.3*m1*a[i].r1+0.7*m2*a[i].r2;       
        sort(a+1,a+n+1,cmp3);  
        printf("The member list of Shandong team is as follows:\n");     
        for(int i=1;i<=n;i++)  
        {  
            if(strcmp(a[i].sex,"female")==0)  
            {  
                f=1;k=i;break;  
            }  
        }  
        if(f)  
        {  
            if(k<=m)  
            {  
                for(int i=1;i<=m;i++)  
                {  
                    printf("%s\n",a[i].name);  
                }  
            }  
            else  
            {  
                for(int i=1;i<m;i++)  
                {  
                    printf("%s\n",a[i].name);   
                }  
                printf("%s\n",a[k].name);  
            }  
        }  
        else  
        {  
            for(int i=1;i<=m;i++)  
            {  
                printf("%s\n",a[i].name);  
            }  
        }  
    }  
    return 0;  
}  