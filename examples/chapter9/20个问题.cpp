/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxm = 11;
const int maxn = 128+5;
const int inf  = 0x3f3f3f3f;
int d[1<<maxm][1<<maxm];
int cnt[1<<maxm][1<<maxm];
int obj[maxn];
int m,n;
int dp(int s, int a){
	int& ans = d[s][a];
	if (ans != inf) return ans;
	if (cnt[s][a] <= 1) return ans = 0;
	if (cnt[s][a] == 2) return ans = 1;
	for (int k=1; k<(1<<m); k = k << 1) {
		if ( (k & s) == k ) continue;
		ans = min(ans, max(dp(s|k, a|k), dp(s|k, a))+1); 
	}
	return ans;
}
int main(void)
{
	while (cin >> m >> n && m) {
		char str[maxm];
		for (int i=0; i<n; ++i) {
			scanf("%s", str);
			obj[i] = 0;
			for (int j=m-1; j>=0; --j) obj[i] |= (str[j] - '0') << (m-j-1);
		}
		
		memset(cnt, 0, sizeof(cnt));
		for (int i=0; i<(1<<m); ++i) {
			for (int k=0; k<n; ++k)
				cnt[i][i & obj[k]]++;
		}
		memset(d, inf, sizeof(d));
		printf("%d\n", dp(0, 0));
	}
	return 0;	
} 
