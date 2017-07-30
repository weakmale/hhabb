#include<cstdio>
int a[111];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int sum=0;
	int s=0;
	for(int i=0;i<n;i++){  
        if(a[i]==0){  
               sum++;
                s=0;  
          }  
        else if(a[i]==1||a[i]==2){  
            if(a[i]==s){  
                    sum++;  
                    s=0;  
            }
			else  
                s=a[i];  
        }
		else 
               s=3-s;
    } 
	printf("%d\n",sum);
	return 0;
}
