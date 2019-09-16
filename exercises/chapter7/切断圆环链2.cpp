#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;

const int maxn=15+5;

int n;
int link_num;
int vis[maxn];
vector<int> g[maxn];

bool dfs(int open,int cur,int pre){
	vis[cur]=1;
	
	for(int i=0;i<g[cur].size();i++){
		if((open&(1<<g[cur][i]))||pre==g[cur][i]) continue;
		
		if(vis[g[cur][i]]) return true;
		if(dfs(open,g[cur][i],cur)) return true; 
	}
	
	return false;
}

bool judge(int open){
	link_num=0;
	int num; //分支数 
	for(int i=0;i<n;i++){
		//判断是否有大于2分支的链 
		if(open&(1<<i)) continue;
		num=0;
		for(int j=0;j<g[i].size();j++){
			if(open&(1<<g[i][j])) continue;
			num++;
		}
		if(num>2) return true;
		
		//判断是否有环路
		if(vis[i]) continue;
		link_num++;
		if(dfs(open,i,-1)) return true; 
	}
	
	return false;
}
int solve(){
	int ans=0x3f3f3f3f;
	
	for(int i=0;i<(1<<n);i++){
		memset(vis,0,sizeof(vis));
		
		if(judge(i)) continue;
		
		int open_num=0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)) open_num++;
		}
		
		if(open_num>=link_num-1) ans=min(ans,open_num);
	}
	return ans;
}
int main(void){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int kcase=0;
	while(cin>>n&&n){
		int u,v;
		
		for(int i=0;i<n;i++) g[i].clear();
		
		while(cin>>u>>v&&u!=-1&&v!=-1){
			g[u-1].push_back(v-1);
			g[v-1].push_back(u-1);
		}
		
		printf("Set %d: Minimum links to open is %d\n",++kcase,solve());
	} 
	//fclose(stdin);
	//fclose(stdout);
}
