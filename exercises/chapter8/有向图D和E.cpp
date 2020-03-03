/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxm = 300+5;
int g[maxm][maxm];
int m,k;

inline 
bool judge()
{
	bool flag1 = true;
	bool flag2 = true;
	for (int u=0; u<m; ++u) {
		for (int v=0; v<m; ++v) {
			if (u == v) continue;
			flag1 = flag2 = true;
			for (int i=0; i<m; ++i) {
				if (i == u || i == v) continue;
				if (g[u][i] && g[v][i])  flag1 = false;
				else if (g[u][i] && !g[v][i]) flag2 = false;
				else if (!g[u][i] && g[v][i]) flag2 = false;
			}
			
			if (!flag1 && !flag2) return false; 
		}
	}
	
	return true;
}
int main(void)
{
	int T;
	int kcase = 0;
	cin >> T;
	while (T--) {
		cin >> m >> k;
		memset(g, 0, sizeof(g));
		
		int u,v;
		for (int i=0; i<k; ++i) {
			cin >> u >> v;
			g[u][v] = 1;
		}
		
		if (judge()) 
			printf("Case #%d: Yes\n", ++kcase);
		else 
			printf("Case #%d: No\n", ++kcase);
	} 
	return 0;
}
