#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn=100000+10;
const int maxm=200000+20;
int m,n; 
int vis[maxn];
int dis[maxn];
int ans[maxn]; 
 
typedef struct Edge{
	int v;
	int color;
	Edge(int v=0,int color=0):v(v),color(color){}
}edge;

vector<edge> g[maxn];

void tail_bfs(){
	memset(vis,0,sizeof(vis));
	queue<int> q;
	q.push(n);
	dis[n]=0;
	vis[n]=1;
	while(!q.empty()){
		int node=q.front();q.pop();
		
		int roads=g[node].size();
		
		for(int i=0;i<roads;i++){
			int next=g[node][i].v;
			
			if(!vis[next]){
				dis[next]=min(dis[node]+1,dis[next]);
				if(next==1) return;
				q.push(next);
				vis[next]=1;
			}
		}
	}
}
void head_bfs(){
	memset(vis,0,sizeof(vis));
	queue<int> q;
	q.push(1);
	vis[1]=1;
	
	while(!q.empty()){
		int node=q.front();q.pop();
		
		int roads=g[node].size();
		int mincolor=0x7fffffff;
		
		for(int i=0;i<roads;i++){
			int next=g[node][i].v;
			int next_color=g[node][i].color;
			
			if(dis[next]==dis[node]-1){
				mincolor=min(mincolor,next_color);
			}
		}
		
		for(int i=0;i<roads;i++){
			int next=g[node][i].v;
			int next_color=g[node][i].color;
			
			if(dis[next]==dis[node]-1&&!vis[next]&&mincolor==next_color){
				q.push(next);
				vis[next]=1;
			}
		}
		int index=dis[1]-dis[node];
		ans[index]=min(ans[index],mincolor);
		
	}
}

int main(void){
	while(cin>>n>>m&&n){
		for(int i=1;i<=n;i++) g[i].clear();
		int u,v,color;
		
		for(int i=0;i<m;i++){
			cin>>u>>v>>color;
			if(u!=v){
				g[u].push_back(edge(v,color));
				g[v].push_back(edge(u,color));
			}
		}
		
		memset(dis,maxm,sizeof(dis));
		memset(ans,maxm,sizeof(ans));
		tail_bfs();
		head_bfs();
		
		printf("%d\n%d",dis[1],ans[0]);
		for(int i=1;i<dis[1];i++){
			printf(" %d",ans[i]);
		}
		printf("\n");
	}
}
