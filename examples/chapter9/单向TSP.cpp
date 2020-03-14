/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int maxm = 10+5;
const int maxn = 100+5;
const int inf = 0x7fffffff;
int matrix[maxm][maxn];
LL dp[maxm][maxn]; //stand for the least sum from (i,j) to n column
int path[maxm][maxn];
int m,n;
int main(void)
{
	while (cin >> m >> n && m) {
		for (int i=0; i<m; ++i) {
			for (int j=1; j<=n; ++j) {
				cin >> matrix[i][j];
			}
		}
		
		int dir[3]; //three different directions
		LL ans = inf;
		int first, temp;
		for (int j=n; j>=1; --j) {
			for (int i=0; i<m; ++i) {
				if (j == n) dp[i][j] = matrix[i][j];
				else {
					dir[0] = i; dir[1] = (i+1)%m; dir[2] = (i-1+m)%m;
					sort(dir, dir+3);
					
					dp[i][j] = inf;
					for(int d=0; d<3; ++d) {
						temp = dp[dir[d]][j+1] + matrix[i][j];
						if (temp < dp[i][j]) {
							dp[i][j] = temp;
							path[i][j] = dir[d];
						}
					} 
				}
				if (j==1 && ans > dp[i][j])  {ans = dp[i][j]; first = i;}
			}
		}
		printf("%d", first+1);
		for (int i=path[first][1], j=2; j<=n; i=path[i][j], ++j){
			printf(" %d", i+1);
		}
		printf("\n%lld\n", ans);
	}
	return 0;
}
