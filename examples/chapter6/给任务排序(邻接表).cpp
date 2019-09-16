#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const int maxn=100+10;

int ans[maxn];
int has_u[maxn];
int n,m,t;
vector<int> g[maxn];


void init_graph(){
	for(int i=1;i<=n;i++){
		g[i].clear();
	}
	memset(has_u,0,sizeof(has_u));
}
int main(void){
	
	while(cin>>n>>m&&n){
		init_graph();
		int u,v;
		for(int i=0;i<m;i++){
			cin>>u;
			cin>>v;
			g[u].push_back(v);
			has_u[v]++;
		}
		
		queue<int> q;
		for(int i=1;i<=n;i++){
			if(has_u[i]==0){
				q.push(i);
			}
		}
		int pos=0;
		while(!q.empty()){
			t=q.front();q.pop();
			
			ans[++pos]=t;
			
			for(int v=0;v<g[t].size();v++){
				if(--has_u[g[t][v]]==0){
					q.push(g[t][v]);
				}
			}
		}
		printf("%d",ans[1]); 
		for(int i=2;i<=pos;i++){
			printf(" %d",ans[i]);
		}
		printf("\n");
	}
}
