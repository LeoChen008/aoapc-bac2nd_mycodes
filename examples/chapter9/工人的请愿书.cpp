/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector> 
using namespace std;

const int maxn = 1e5+5;
vector<int> employ[maxn];
int t, n;

int dp(int a)
{
	int size = employ[a].size();
	if (size == 0) return 1;
	
	vector<int> d;
	for (int i=0; i<size; ++i) d.push_back(dp(employ[a][i]));
	sort(d.begin(), d.end());
	int c = (size*t - 1)/100 + 1;
	
	int ans = 0;
	for (int i=0; i<c; ++i) {
		ans += d[i];
	}	
	
	return ans;
}
int main(void)
{
	while (cin >> n >> t && n) {
		for (int i=0; i<=n; ++i) employ[i].clear();
		
		int owner;	
		for (int i=1; i<=n; ++i) {
			cin >> owner;
			employ[owner].push_back(i); 
		}
		printf("%d\n", dp(0));
	}
	return 0;
}
