#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

#define DEBUG
const int maxn=100+5;

int sticks[maxn],vis[maxn];
int n,maxlen,sumlen;

bool cmp(const int &a,const int &b){
	return a>b;
}
bool dfs(int cnt,int cur,int lens,int target){
	if(cnt*target==sumlen){
		return true;
	}
	
	for(int i=cur;i<n;i++){
		if(vis[i]||(i&&!vis[i-1]&&sticks[i]==sticks[i-1])) continue;
		
		if(sticks[i]+lens==target){
			vis[i]=1;
			if(dfs(cnt+1,0,0,target))return true;
			vis[i]=0;
			return false;
		}
		else if(sticks[i]+lens<target){
			vis[i]=1;
			if(dfs(cnt,cur+1,sticks[i]+lens,target)) return true;
			vis[i]=0;
			if(lens==0) return false;
		}
		
	}
	
	return false;
}
int solve(){
	sort(sticks,sticks+n,cmp);
	
	int ans=-1;
	for(int i=sticks[0];i<=sumlen;i++){
		memset(vis,0,sizeof(vis));
		if(sumlen%i==0&&sticks[0]<=i){
			if(dfs(0,0,0,i)){
				ans=i;
				break;
			}
		}
	}
	
	return ans;
}
int main(void){
	#ifdef _DEBUG
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	while(cin>>n&&n){
		maxlen=-1;sumlen=0;
		for(int i=0;i<n;i++){
			cin>>sticks[i];
			sumlen+=sticks[i];
		}
		
		printf("%d\n",solve());
	}
	fclose(stdin);
	fclose(stdout);
} 
