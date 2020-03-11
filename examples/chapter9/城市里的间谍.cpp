/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

const int maxn = 50+5;
const int maxt = 200+5;
const int inf = 0x3f3f3f3f;

int dp[maxt][maxn];  // stand for the least wait times of which station at a certain time 
int d1[maxn],d2[maxn];
int train[maxt][maxn][2];
int cost_t[maxn];
int n,t;
int m1,m2;

inline
int solve()
{
	for (int i=1; i<=n-1; ++i) dp[t][i] = inf;
	dp[t][n] = 0;
	
	for (int i=t-1; i>=0; --i) {
		for (int j=1; j<=n; ++j) {
			dp[i][j] = dp[i+1][j] + 1; // wait one unit long
			if (j<n && train[i][j][0] && i+cost_t[j]<=t)   //left to right
				dp[i][j] = min(dp[i][j], dp[i+cost_t[j]][j+1]);
			if (j>1 && train[i][j][1] && i+cost_t[j-1]<=t) // right to left  
				dp[i][j] = min(dp[i][j], dp[i+cost_t[j-1]][j-1]);    
		}
	}
	
	if (dp[0][1] >= inf) return -1;
	else return dp[0][1];	
}
int main(void)
{
	int kcase = 0;
	int ans = 0;
	while (cin >> n && n) {
		cin >> t;
		for (int i=1; i<=n-1; ++i) cin >> cost_t[i];
		
		memset(train, 0, sizeof(train)); 
		
		cin >> m1;
		int start;
		for (int i=1; i<=m1; ++i) {
			cin >> start;
			
			for (int j=1; j<=n-1; ++j) {
				if (start <= t) train[start][j][0] = 1;
				start += cost_t[j];
			}
		}
		cin >> m2;
		for (int i=1; i<=m2; ++i) {
			cin >> start;
			
			for (int j=n-1; j>=1; --j) {
				if (start <= t) train[start][j+1][1] = 1;
				start += cost_t[j];
			}
		}
		
		ans = solve();
		if (ans == -1) printf("Case Number %d: impossible\n", ++kcase);
		else printf("Case Number %d: %d\n", ++kcase, ans);
		
	} 
	return 0;
} 
