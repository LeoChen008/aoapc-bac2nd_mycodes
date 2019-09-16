#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

const int maxn=100+10;

int g[maxn][maxn];
int vis[maxn];
int ans[maxn];
int n,m;
int t;

bool dfs(int a){
	vis[a]=-1;
	
	for(int b=1;b<=n;b++){
		if(g[a][b]==1){
			if(vis[b]==-1){ //存在有向环,无法排序 
				return false;
			}
			else if(vis[b]==0&&!dfs(b)){
				return false;
			}
		}
	}
	
	vis[a]=1;
	ans[t--]=a;
	return true;
}
bool toposort(){//拓扑排序
	t=n;
	
	memset(vis,0,sizeof(vis));
	
	for(int a=1;a<=n;a++){
		if(!vis[a]){
			if(!dfs(a)){
				return false;
			}
		}
	}
	return true;
}
int main(void){
	while(cin>>n>>m&&n){		
		memset(g,0,sizeof(g));
		int a,b;
		for(int i=0;i<m;i++){
			cin>>a;
			cin>>b;
			g[a][b]=1;
		}
		
		if(toposort()){
			printf("%d",ans[1]);
			for(int i=2;i<=n;i++){
				printf(" %d",ans[i]);
			}
		}
		printf("\n");	
	}	
}
