#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

typedef long long LL;
int kcase=0;
int n,s1,v1,s2,v2;
LL ans;

int main(void){
	int T;
	cin>>T;
	while(T--){
		cin>>n>>s1>>v1>>s2>>v2;
		ans=0;
		
		int t;
		if(s1>=s2){
			t=s1;
		}else{
			t=s2;
		} 
		
		if(n/t>=(1<<16)){
			for(LL i=0;i<=s2;i++){
				ans=max(ans,v1*i+(n-i*s1)/s2*v2);
			}
			
			for(LL i=0;i<=s1;i++){
				ans=max(ans,v2*i+(n-i*s2)/s1*v1);
			}
		}
		else{
			if(t==s1){
				for(LL i=0;s1*i<=n;i++){
					ans=max(ans,v1*i+(n-i*s1)/s2*v2);
				}
			}
			else if(t==s2){
				for(LL i=0;s2*i<=n;i++){
					ans=max(ans,v2*i+(n-i*s2)/s1*v1);
				}
			}
		}
		printf("Case #%d: %lld\n",++kcase,ans);
	}
} 
