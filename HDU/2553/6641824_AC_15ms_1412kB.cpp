#include<cstdio>
#include<cstring>
int n;
int qp[20];
int t=0;
int ans[20];
int m;
void DFS(int l)
{
    int i,j;
    if(l==n+1)
    {
        t++;
        return;
    }
    else
    {
        for(i=1;i<=n;++i)
        {
            qp[l]=i;
            bool k=true;
            for(j=1;j<l;++j)
            {
                if(qp[j]==i||i-l==qp[j]-j||i+l==qp[j]+j)  
                {
                    k=false;
                    break;
                }
            }
            if(k)
                DFS(l+1);
        }
    }
}

int main(){
	for(n=1;n<11;n++)
    {
         t=0;
         DFS(1);
         ans[n]=t;
     }
	while(scanf("%d",&m),m){
		printf("%d\n",ans[m]);		
	}
}