/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 100+5;
char str[maxn];
// dp[i][j] the minimum numbers of bracket needed to be add from i to j
int dp[maxn][maxn];
int n;

inline
bool judge(int st, int ed) 
{
	return (str[st] == '(' && str[ed] == ')') || (str[st] == '[' && str[ed] == ']');
}
void solve() 
{
	for (int i=0; i<n; ++i) {
		dp[i][i] = 1;
		dp[i+1][i] = 0;
	}
	for (int i=n-2; i>=0; --i) {
		for (int j=i+1; j<n; ++j) {
			dp[i][j] = n;

			if (judge(i, j)) dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
			for (int k=i; k<j; ++k) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
			}
		}
	}
}
void print(int st, int ed)
{
	if (st > ed) return ;
	if (st == ed) {
		if (str[st] == '(' || str[st] == ')') printf("()");
		else printf("[]");
		return ;
	}
	
	if (judge(st, ed) && dp[st][ed] == dp[st+1][ed-1]) {
		putchar(str[st]);
		print(st+1, ed-1);
		putchar(str[ed]);
		return ;
	}
	
	for (int k=st; k<ed; ++k) {
		if (dp[st][ed] == dp[st][k] + dp[k+1][ed]) {
			print(st, k);
			print(k+1, ed);
			return ;
		}
	}
}
int main(void) {
	int T;
	scanf("%d", &T);
	getchar();
	while (T--) {
		getchar();
		fgets(str, maxn, stdin);
		n = strlen(str) - 1;
		
		solve();
		print(0, n-1);
		printf("\n");
		if (T) printf("\n"); 
	}
	return 0;
}
