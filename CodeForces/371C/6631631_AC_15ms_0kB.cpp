#include<cstdio>
char sr[111];
__int64 n;
__int64 b,s,c;
__int64 bm,sm,cm;
__int64 mny;
__int64 bi,si,ci;
bool judge(__int64 mid){
	__int64 b1=mid*bi-b,s1=mid*si-s,c1=mid*ci-c;
	__int64 cnt=mny;
	if(b1>0)
	cnt-=b1*bm;
	if(c1>0)
	cnt-=c1*cm;
	if(s1>0)
	cnt-=s1*sm;
	return cnt>=0;
}
int main(){
	scanf("%s",sr);
	scanf("%I64d%I64d%I64d",&b,&s,&c);
	scanf("%I64d%I64d%I64d",&bm,&sm,&cm);
	scanf("%I64d",&mny);
	for(int i=0;sr[i];i++){
		if(sr[i]=='B')
			bi++;
		if(sr[i]=='S')
			si++;
		if(sr[i]=='C')
			ci++;
	}
	__int64 l=0,r=2000000000000,ans=0;
	while(l<=r){
		__int64 mid=(l+r)>>1;
		if(judge(mid)) {
			ans=mid;
			l=mid+1;
		} 
		else {
			r=mid-1;
		} 
	}
	printf("%I64d",ans);
	return 0;
}