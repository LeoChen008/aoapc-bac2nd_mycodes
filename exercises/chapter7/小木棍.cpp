#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

const int maxn=50+5;
int sticks[maxn];
int vis[maxn];
int n;
int maxl,sum;

bool dfs(int cur,int next,int sl,int len){
	if(cur==n){
		return true;
	}
	
	for(int i=next;i<n;i++){
		if(vis[i]) continue;
		if(sticks[i]+sl<len){
			vis[i]=1;
			if(dfs(cur+1,next+1,sticks[i]+sl,len)) return true;
			vis[i]=0;
			while(i+1<n&&sticks[i]==sticks[i+1]) i++;
			if(sl==0) return false; 
		}
		else if(sticks[i]+sl==len){
			vis[i]=1;
			if(dfs(cur+1,0,0,len)) return true;
			vis[i]=0;
		}
	}
	
	return false;
}
void solve(){
	sort(sticks,sticks+n);
	for(int len=maxl;len<=sum;len++){
		memset(vis,0,sizeof(vis));
		if(sum%len==0&&dfs(0,0,0,len)){
			printf("%d\n",len);
			return;
		}
	} 
}
int main(void){
	while(cin>>n&&n){
		maxl=-1;sum=0;
		for(int i=0;i<n;i++){
			cin>>sticks[i];
			maxl=max(maxl,sticks[i]);
			sum+=sticks[i];
		}
		solve();
	}
} 
