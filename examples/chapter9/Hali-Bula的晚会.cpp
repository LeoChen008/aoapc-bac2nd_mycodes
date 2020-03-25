/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
const int maxn = 200+5;

vector<int> employ[maxn];
map<string, int> m;
int d[maxn][2], f[maxn][2];
int n, cnt;
inline
int get_id(const string& str) {
	if (!m.count(str)) m[str] = cnt++;
	return m[str];
}

int dp(int u, int k) {
	d[u][k] = k;
	f[u][k] = 1;
	int size = employ[u].size();
	int v, temp1, temp2;
	for (int i=0; i<size; ++i) {
		int v = employ[u][i];
		if (k) {
			d[u][k] += dp(v, 0);
			if (!f[v][0]) f[u][k] = 0;
		}
		else {
			temp1 = dp(v, 0); temp2 = dp(v, 1);
			if (temp1 == temp2) { f[u][k] = 0; d[u][k] += temp1;}
			else if (temp1 > temp2) { f[u][k] = f[v][0] == 0 ? 0:f[u][k]; d[u][k] += temp1;}
			else { f[u][k] = f[v][1] == 0 ? 0:f[u][k]; d[u][k] += temp2;}
		}
	}
	return d[u][k]; 
}
int main(void) 
{ 
	string boss, emp;
	while (cin >> n && n) {
		for (int i=0; i<n; ++i) employ[i].clear();
		m.clear();
		cnt = 0;
		cin >> boss;
		get_id(boss);
		
		for (int i=1; i<n; ++i) {
			cin >> emp >> boss;
			employ[get_id(boss)].push_back(get_id(emp));
		}
		
		printf("%d ", max(dp(0, 0), dp(0, 1)));
		if ( (d[0][1] > d[0][0] && f[0][1]) || (d[0][0] > d[0][1] && f[0][0])) printf("Yes\n");
		else printf("No\n");  
	}
	return 0;
}
