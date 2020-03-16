/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1000+5;

struct Lamp{
	int v,k,c,l;
	bool operator< (const Lamp& rhs) const {
		return this->v < rhs.v;
	} 
}lamps[maxn];
int dp[maxn]; //dp[i] stand for the least money costed by first i lamps
int s[maxn];
int n;
 
int main(void)
{
	while (cin >> n && n) {
		for (int i=1; i<=n; ++i) {
			cin >> lamps[i].v >> lamps[i].k >> lamps[i].c >> lamps[i].l;
		}
		sort(lamps+1, lamps+n+1);

		s[0] = 0;		
		for (int i=1; i<=n; ++i) s[i] = s[i-1] + lamps[i].l;
		
		dp[0] = 0;
		for (int i=1; i<=n; ++i) {
			dp[i] = s[i]*lamps[i].c + lamps[i].k;
			for (int j=1; j<=i; ++j) {
				dp[i] = min(dp[i], dp[j]+(s[i]-s[j])*lamps[i].c+lamps[i].k);
			}
		}
		
		printf("%d\n", dp[n]);
		
	}
	return 0;
}

