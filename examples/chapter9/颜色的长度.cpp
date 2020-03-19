/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 5000+5;
const int maxcol = 26;
const int inf = 0x3f3f3f3f;

struct Color{
	int st1, ed1;
	int st2, ed2;
	Color(int x=inf,int y=0,int p=inf,int q=0):st1(x),ed1(y),st2(p),ed2(q){}
	void init(){
		this->st1 = this->st2 = inf;
		this->ed1 = this->ed2 = 0;
	}
}cols[maxcol];

char s1[maxn], s2[maxn];
int dp[maxn][maxn];
int cnt[maxn][maxn];
int n,m;

void solve()
{	
	dp[0][0] = 0;
	cnt[0][0] = 0;
	for (int i=0; i<=n; ++i) {
		for (int j=0; j<=m; ++j) {
			if (!i && !j) continue;
			
			dp[i][j] = inf;
			if (i) {
				dp[i][j] = min(dp[i][j], dp[i-1][j] + cnt[i-1][j]);
				cnt[i][j] = cnt[i-1][j];
				if (cols[s1[i]-'A'].st1 == i && cols[s1[i]-'A'].st2 > j) cnt[i][j]++;
				if (cols[s1[i]-'A'].ed1 == i && cols[s1[i]-'A'].ed2 <= j) cnt[i][j]--;
			} 
			if (j) {
				dp[i][j] = min(dp[i][j], dp[i][j-1] + cnt[i][j-1]);
				cnt[i][j] = cnt[i][j-1];
				if (cols[s2[j]-'A'].st2 == j && cols[s2[j]-'A'].st1 > i) cnt[i][j]++;
				if (cols[s2[j]-'A'].ed2 == j && cols[s2[j]-'A'].ed1 <= i) cnt[i][j]--;
			}
		}
	}
} 
int main(void)
{
	int T;
	cin >> T;
	while (T--) {
		scanf("%s", s1+1);
		scanf("%s", s2+1);
		n = strlen(s1+1);
		m = strlen(s2+1);
		
		for (int i=0; i<maxcol; ++i) cols[i].init();
		int index;
		for (int i=1; i<=n; ++i) {
			index = s1[i] - 'A';
			if (cols[index].st1 == inf) cols[index].st1 = i;
			cols[index].ed1 = max(i, cols[index].ed1);
		}
		
		for (int i=1; i<=m; ++i) {
			index = s2[i] - 'A';
			if (cols[index].st2 == inf) cols[index].st2 = i;
			cols[index].ed2 = max(i, cols[index].ed2);
		}
		
		solve();
		
		printf("%d\n", dp[n][m]); 
	}
	return 0;
}
