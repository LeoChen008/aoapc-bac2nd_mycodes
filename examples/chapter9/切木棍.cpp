/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 50+5;
const int inf = 0x3f3f3f3f;

//dp[i][j] the minimum of cost from i to j
int dp[maxn][maxn]; 
int a[maxn];
int n,l; 
int main(void)
{
	while (cin >> l && l) {
		cin >> n;
		for (int i=1; i<=n; ++i) cin >> a[i];
		
		a[0] = 0; a[n+1] = l;
		
		int temp;
		int j;
		for (int dis=1; dis<=n+1; ++dis) {
			for (int i=0; i<=n; ++i) {
				j = i + dis;
				if (j > n+1) continue;
				
				dp[i][j] = inf;
				for (int k=i+1; k<j; ++k) {
					temp = dp[i][k] + dp[k][j];
					dp[i][j] = min(dp[i][j], temp);
				}
				
				if (dp[i][j] == inf) dp[i][j] = a[j] - a[i];
				else dp[i][j] += a[j] - a[i];
			}
		}
		
		printf("The minimum cutting is %d.\n", dp[0][n+1]-l);
	}
	return 0;
} 
