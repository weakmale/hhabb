#include <cstdio>
#include <string>
#include <map>
#include <iostream>
using namespace std;
int main(){
    map<string,string> M;
    map<int,string> M1;
    map<string,int> M2;
    char s1[25],s2[25];
    int n;
    scanf("%d",&n);
    int k=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%s %s",s1,s2);
        if(M2[s1]==0){
            M[s1]=s2; M1[++k]=s1; M2[s1]=1; M2[s2]=1;
        }
        else{
            for(int i=1;i<=k;i++){
                if(M[M1[i]]==s1){
                    M[M1[i]]=s2; M2[s1]=0; M2[s2]=1;
                }
            }
        }
    }
    printf("%d\n",k);
    for(int i=1;i<=k;i++)
        cout<<M1[i]<<" "<<M[M1[i]]<<endl;
    return 0;
}
