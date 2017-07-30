#include<cstdio>
int main()
{
	char a[1001],b[10001];
	while(scanf("%s",a)&&a[0]!='#'){
		scanf("%s",b);
		int i=0,j=0,t=0;
		while(a[i]){
			j=0;int k=1;int l=i;
			while(b[j]){
				if(b[j]!=a[l]){
					k=0;break;
				}
				j++; l++;
			}
			 if(k){
			  t++; i=l;}
			 else
			 	i++;
		}
		printf("%d\n",t);
	}
	return 0;
}