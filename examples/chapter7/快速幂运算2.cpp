#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;

const int maxn=1000+50;
const int maxm=13;
int n;
int a[maxn];


bool dfs(int cur,int maxd){
	if(a[cur]==n) return true;
	if(cur==maxd) return false;
	
	int maxv=-1;
	for(int i=0;i<=cur;i++) maxv=max(maxv,a[i]);
	if((maxv<<(maxd-cur))<n) return false;
	
	for(int i=cur;i>=0;i--){
		if(a[cur]<n){
			a[cur+1]=a[cur]+a[i];
			if(dfs(cur+1,maxd)) return true;
		}
		if(a[cur]-a[i]>0){
			a[cur+1]=a[cur]-a[i];
			if(dfs(cur+1,maxd)) return true;
		}
	}
	
	return false;
}
int solve(){
	if(n==1) return 0;
	a[0]=1;
	for(int maxd=1;maxd<maxm;maxd++){
		if(dfs(0,maxd)) return maxd;
	}
	return maxm;
}
int main(void){
	
	while(cin>>n&&n){
		printf("%d\n",solve());
	}
} 
