#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;  
const int maxn=100010;  
bool vis[maxn];  
long long num[maxn]; 
int n;  
long long k; 
int main()  
{  
    scanf("%d%lld",&n,&k);  
    for(int i=1;i<=n;++i)
        scanf("%lld",&num[i]);  
    sort(num+1,num+n+1);  
    memset(vis,false,sizeof(vis));  
    int ans=n;  
    for(int i=1;i<=n;++i){  
        if(vis[i])continue;  
        int l=i+1,r=n;  
        long long t = num[i]*k;  
        while(l<=r){  
            int mid=(l+r)>>1;  
            if(num[mid]==t){  
                vis[mid]=true;
				ans--;
				break;  
            }  
            else if(num[mid]>t){  
                r=mid-1;  
            }  
            else{  
                l=mid+1;  
            }  
        }  
    }  
    printf("%d\n",ans);  
    return 0;  
}  
