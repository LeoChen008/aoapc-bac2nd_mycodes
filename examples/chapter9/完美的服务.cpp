/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 10000+5;
vector<int> songs[maxn];
int d[maxn][3];  //d[i] minimum numbers of servers which i is root 
int n;

void dfs(int u, int f)
{
	d[u][0] = 1;
	d[u][1] = 0;
	d[u][2] = maxn;
	int size = songs[u].size();
	
	int v;
	for (int i=0; i<size; ++i) {
		v = songs[u][i];
		if (v != f) {  // v is song 
			dfs(v, u); 
			d[u][0] += min(d[v][0], d[v][1]); // u is server  
			d[u][1] += d[v][2];               // u isn't a server, but u's father is server
		}
	}
	for (int i=0; i<size; ++i) {
		v = songs[u][i];
		if (v != f) {
			d[u][2] = min(d[u][2], d[u][1] - d[v][2] + d[v][0]);      // u isn't a server neither u's father is
		}
	}
	
}
int main(void)
{
	while (cin >> n) {
		for (int i=1; i<=n; ++i) songs[i].clear();
		
		int u,v;
		for (int i=1; i<n; ++i) {
			cin >> u >> v;
			songs[u].push_back(v);
			songs[v].push_back(u); 
		}
		
		dfs(1, -1);
		printf("%d\n", min(d[1][0], d[1][2]));
		int flag;
		cin >> flag;
		if (flag == -1) break;
	}
	return 0;
}
