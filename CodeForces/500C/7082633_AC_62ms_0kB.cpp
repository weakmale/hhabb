#include "cstdio"
#include "queue"
#include "vector"
using namespace std;
int w[510];
bool vis[510];
int main(){
    vector<int> G;
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);
    int sum=0; int s;
    scanf("%d",&s);
    vis[s]=true; G.insert(G.begin(), s);
    for(int i=1;i<m;i++){
        scanf("%d",&s);
        if(!vis[s]){
            vis[s]=true;
            for(int i=0;i<G.size();i++)
                sum+=w[G[i]];
            G.insert(G.begin(), s);
        }
        else{
            int k=0;
            for(int i=0;i<G.size();i++){
                if(G[i]==s){
                    k=i;break;
                }
            }
            for(int i=0;i<k;i++){
                sum+=w[G[i]];
                G.insert(G.begin()+k+i+1, G[i]);
            }
            for(int i=0;i<k;i++)
                G.erase(G.begin());
        }
//        for(int i=0;i<G.size();i++)
//            printf("%d",G[i]);
    }
    printf("%d\n",sum);
    return 0;
}