#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn=21+5;

int num;
int fire;
int kcase=0;
int routes[maxn];
int vis[maxn];
int openpath[maxn];
vector<int> ans[maxn];
vector<int> g[maxn];


void init(){
	num=0;
	memset(routes,0,sizeof(routes));
	memset(vis,0,sizeof(vis));
	memset(openpath,0,sizeof(openpath));
	for(int i=0;i<maxn;i++){
		g[i].clear();
		ans[i].clear();
	}
}

void dfs(int cur){
	if(routes[cur]==fire){
		for(int i=0;i<=cur;i++){
			ans[num].push_back(routes[i]);
		}
		num++;
		return;
	}
	vector<int> next=g[routes[cur]];
	for(int i=0;i<next.size();i++){
		if(!vis[next[i]]&&openpath[next[i]]){
			vis[next[i]]=1;
			routes[cur+1]=next[i];
			dfs(cur+1);
			vis[next[i]]=0;
		}
	}
}
void bfs(int a){
	queue<int> q;
	q.push(a);
	
	while(!q.empty()){
		int corner=q.front();q.pop();
		
		vector<int> next=g[corner];
		for(int i=0;i<next.size();i++){
			if(!openpath[next[i]]){
				openpath[next[i]]=1;
				q.push(next[i]);
			}
		}
	}
}
void print_routes(){
	printf("CASE %d:\n",++kcase);
	for(int i=0;i<num;i++){
		printf("%d",ans[i][0]);
		for(int j=1;j<ans[i].size();j++){
			printf(" %d",ans[i][j]);
		}
		printf("\n");
	} 
	
	printf("There are %d routes from the firestation to streetcorner %d.\n",num,fire);
}
void solve(){
	routes[0]=1;
	vis[1]=1;
	
	bfs(fire); //To mark the path to the destination
	
	dfs(0);    
	
	print_routes();
}
int main(void){
	while(cin>>fire){
		init();
		int u,v;
		while(cin>>u>>v&&u&&v){
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i=0;i<maxn;i++){
			if(!g[i].empty()){
				sort(g[i].begin(),g[i].end());
			}
		}
		solve();
	}
} 
