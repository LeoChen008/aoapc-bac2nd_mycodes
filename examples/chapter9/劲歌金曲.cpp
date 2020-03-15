/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring> 
using namespace std;

const int maxn = 50+5;
const int JGJQ = 678;
const int maxt = 180*maxn+JGJQ;

//dp[i][j] the maximal numbers of songs from  ith songs, wheres the length of songs is j seconds
int dp[maxt]; 
int cost_t[maxn];
int n,t;
int main(void)
{
	int kcase = 0;
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> t;
		t--;
		
		for (int i=1; i<=n; ++i) cin >> cost_t[i];
		
		memset(dp, 0, sizeof(dp));
		
		int ans = 0;
		for (int i=1; i<=n; ++i) {
			for (int j=t; j>=cost_t[i]; --j) {
				if (j == cost_t[i] || dp[j-cost_t[i]] >= 1) 
					dp[j] = max(dp[j], dp[j-cost_t[i]] + 1);
				ans = max(ans, dp[j]);
			}
		}
		
		for (int i=t; i>=0; --i) 
			if(ans && ans == dp[i]) {
				printf("Case %d: %d %d\n", ++kcase, ans+1, i+JGJQ);
				break;
			}
			else if (!ans) {
				printf("Case %d: %d %d\n", ++kcase, ans+1, JGJQ);
				break;
			}
	} 
	return 0;
}
