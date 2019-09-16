#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

const int maxn=100000+10;
const int maxm=200000+10;

int vis[maxn]; 
int dis[maxn];
 
int n,m;

typedef struct Edge{
	int v;
	int color;
	Edge(int v=0,int color=0):v(v),color(color){}
}edge;

struct Pre{
	int prenode;
	int index;
	Pre(int prenode=0,int index=0):prenode(prenode),index(index){}
}pre[maxn];

vector<edge> g[maxn];


void bfs(){
	memset(vis,0,sizeof(vis));
	memset(dis,0x7fffffff,sizeof(dis));
	queue<int> q;
	q.push(n);
	vis[n]=1;
	dis[n]=0;
	pre[n]=Pre(-1,-1);
	
	while(!q.empty()){
		int node=q.front();q.pop(); 
		 
		int roads=g[node].size();
		
		for(int i=0;i<roads;i++){
			int next=g[node][i].v;
			
			if(!vis[next]){
				pre[next]=Pre(node,i);
				dis[next]=dis[node]+1;
				q.push(next);
				vis[next]=1;
			}else{
				if(dis[next]==dis[node]+1){
					Pre x=pre[next];Pre y=Pre(node,i);
					while(x.index!=y.index&&x.prenode!=-1&&y.prenode!=-1&&g[x.prenode][x.index].color==g[y.prenode][y.index].color){
						x=pre[x.prenode];
						y=pre[y.prenode];
					}
					if(x.prenode!=-1&&y.prenode!=-1&&g[x.prenode][x.index].color>g[y.prenode][y.index].color){
						pre[next]=Pre(node,i);
					}
				}
			}
		}
	}
}
int main(void){
	while(cin>>n>>m){
		for(int i=1;i<=n;i++) g[i].clear();
		int u,v,color; 
		while(m--){
			cin>>u>>v>>color;
			
			if(u!=v){
				g[u].push_back(edge(v,color));
				g[v].push_back(edge(u,color));
			}
		}
		
		bfs();
		
		Pre n;
		n=pre[1];
		printf("%d\n%d",dis[1],g[n.prenode][n.index].color);
		for(n=pre[n.prenode];n.prenode!=-1;n=pre[n.prenode]){
			printf(" %d",g[n.prenode][n.index].color);
		}
		printf("\n");
	}
}
