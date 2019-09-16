#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

const int maxn=15+5;

int n;
int m;
int vis[maxn];
int g[maxn][maxn];

bool dfs(int open,int cur,int pre){
	vis[cur]=1;
	for(int i=0;i<n;i++){
		if(!g[cur][i]||((1<<i)&open)||pre==i) continue;
		if(vis[i]) return true;
		if(dfs(open,i,cur)) return true;
	}
	
	return false;
} 

bool judge(int open){
	int count;
	m=0;
	for(int i=0;i<n;i++){
		if(open&(1<<i)) continue;
		
		count=0;
		for(int j=0;j<n;j++){
			if(open&(1<<j)) continue;
			
			if(g[i][j])count++;
		}
		if(count>2) return true;
		
		if(vis[i]) continue;
		m++;
		if(dfs(open,i,-1)) return true;
		
	}
	
	return false;
}
int solve(){
	int ans=0x3f3f3f3f;
	for(int i=0;i<(1<<n);i++){
		memset(vis,0,sizeof(vis));
		if(judge(i)) continue;//To judge whether chain links are circles or have more than two chain links connect with.
		int num1=0;
		for(int j=0;j<n;j++){
			if((1<<j)&i) num1++;
		}
		if(num1>=m-1) ans=min(ans,num1);
	}
	
	return ans;
}
int main(void){
	int kcase=0;
	while(cin>>n&&n){
		memset(g,0,sizeof(g));
		
		int u,v;
		while(cin>>u>>v&&u!=-1&&v!=-1){
			g[u-1][v-1]=1;
			g[v-1][u-1]=1;
		}
		
		printf("Set %d: Minimum links to open is %d\n",++kcase,solve()); 
	}
} 
