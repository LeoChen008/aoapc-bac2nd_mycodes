/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 9999+5;
const int maxm = (100000+5)*2;

int head[maxn];
int degree[maxn],color[maxn],vis[maxn];
int n,m; 
int ecnt;
int maxdegree;

struct Edge{
	int v,nxt;
}edge[maxm];

inline
void add_edge(int u, int v) {
	edge[ecnt].v = v;
	edge[ecnt].nxt = head[u];
	head[u] = ecnt++;
}

void dfs(int start) {
	
	int next;
	for (int i=head[start]; i!=-1; i=edge[i].nxt) {
		next = edge[i].v;
		vis[color[next]] = start;
	}
	
	for(int i=1; i<=maxdegree; ++i) {
		if (vis[i] != start) {
			color[start] = i;
			break;
		}
	}
	
	for(int i=head[start]; i!=-1; i=edge[i].nxt) {
		next = edge[i].v;
		if (!color[next]) dfs(next);
	}
}
int main(void)
{
	int u,v;
	int kcase = 0;
	int maxvertex;
	while (cin >> n >> m) {
		
		ecnt = 0;
		maxdegree = maxvertex = 0;
		memset(head+1, -1, sizeof(int)*n);
		memset(color+1, 0, sizeof(int)*n);
		memset(degree+1, 0 ,sizeof(int)*n);
		
		for (int i=0; i<m; ++i) {
			cin >> u >> v;
			
			add_edge(u,v);
			add_edge(v,u);
			degree[u]++;
			degree[v]++; 
		}
		
		for (int i=1; i<=n; ++i) {
			if (degree[i] > maxdegree) {
				maxdegree = degree[i];
				maxvertex = i;
			}
		}
		
		maxdegree = maxdegree | 1;
		memset(vis+1, 0, sizeof(int)*n);
		dfs(maxvertex);
		
		printf("%d\n", maxdegree);
		
		for(int i=1; i<=n; ++i) printf("%d\n", color[i]);
		
		printf("\n");
	}
	return 0;
}
