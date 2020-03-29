/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
using namespace std;
const int maxm = 20+5;
const int maxn = 100+5;
const int maxt = maxm+maxn;
const int maxs = 8;
const int inf  = 0x3f3f3f3f;
int c[maxt];
int st[maxt];
int d[maxt][1<<maxs][1<<maxs];
int s,m,n;

int dp(int i, int s0, int s1, int s2)
{
	if (i >= m+n) return s2 == (1<<s)-1 ? 0:inf;
	int& ans = d[i][s1][s2];
	if (ans >= 0) return ans;
	
	ans = inf;
	if (i >= m) ans = dp(i+1, s0, s1, s2);
	
	int temp1 = s0 & st[i];
	int temp2 = s1 & st[i];
	
	s0 ^= temp1;
	s1 = (s1 ^ temp2) | temp1;
	s2 |= temp2;
	
	ans = min(ans, dp(i+1, s0, s1, s2) + c[i]);
	return ans;
}
int main(void)
{
	while (cin >> s >> m >> n && s) {
		getchar();
		string line;
		int temp;
		for (int i=0; i<m+n; ++i) {
			getline(cin, line);
			stringstream ss(line);
			ss >> c[i];
			st[i] = 0;
			while (ss >> temp) st[i] |= 1<<(temp-1);
		}
		memset(d, -1, sizeof(d));
		printf("%d\n", dp(0, (1<<s)-1, 0, 0));
	}
	return 0;
} 
