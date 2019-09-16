#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;

const int maxn=1000+10;

int count;
int V,E,T; 
int kcase=0;
int vis[maxn];
vector<int> g[maxn];

void dfs(int city,int &a){
	if(vis[city]) return;	
	vis[city]=1;
	
	int size=g[city].size();

	if(size%2==1) a++;
	
	for(int i=0;i<size;i++){
		dfs(g[city][i],a);
	}
	
	return;
}

int main(void){
	
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
		
	while(cin>>V>>E>>T&&V){
		for(int i=1;i<=V;i++) g[i].clear();
		memset(vis,0,sizeof(vis));
		
		for(int i=1;i<=E;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		count=0;
		
		for(int i=1;i<=V;i++){
			if(!vis[i]&&!g[i].empty()){
				int a=0;
				dfs(i,a);
				count+=max(a,2);
			}
		}
		
		printf("Case %d: %d\n",++kcase,T*(max(count/2-1,0)+E));
	}
	
	//fclose(stdin);
	//fclose(stdout);
} 
