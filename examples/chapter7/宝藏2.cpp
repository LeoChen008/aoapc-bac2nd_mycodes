#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

typedef long long LL;
int n,s1,v1,s2,v2;
int kcase=0;

int main(void){
	
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int T;
	cin>>T;
	while(T--){
		cin>>n>>s1>>v1>>s2>>v2;
		LL ans=0;
		
		int t;
		t=max(s1,s2);
		
		//进行分类枚举 
		if(n/t>=(1<<16)){
			//如果n/s1或n/s2都很大
			if(s2*v1>=s1*v2){
				for(LL i=0;i<s1;i++){
					ans=max(ans,v2*i+(n-s2*i)/s1*v1);
				}
			}
			else{
				for(LL i=0;i<s2;i++){
					ans=max(ans,v1*i+(n-s1*i)/s2*v2);
				}
			}
		}else{
			//如果n/s1较小或s2较小
			if(t==s1){
				for(LL i=0;s1*i<=n;i++){
					ans=max(ans,i*v1+(n-i*s1)/s2*v2);
				}
			}else{
				for(LL i=0;s2*i<=n;i++){
					ans=max(ans,i*v2+(n-i*s2)/s1*v1);
				}
			}
		}
		
		printf("Case #%d: %lld\n",++kcase,ans);
	}
	
	//fclose(stdin);
	//fclose(stdout);
}
