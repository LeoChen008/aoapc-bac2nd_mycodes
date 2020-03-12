/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

const int maxn = 1000+5;
struct Point{
	int x,y;
}p[maxn];
double dp[maxn][maxn];  // stand for the least length of distant to final point
double dist[maxn][maxn];
int n;

inline
double get_dis(int a, int b)
{
	return sqrt(pow((double)(p[a].x-p[b].x),2) + pow((double)(p[a].y-p[b].y),2));
}
int main(void)
{
	while(cin >> n && n) {
		for (int i=1; i<=n; ++i) {
			cin >> p[i].x >> p[i].y;
		} 
		
		for (int i=1; i<=n; ++i)
			for (int j=1; j<=n; ++j)
				dist[i][j] = get_dis(i, j);
 
		dp[n][n] = 0;	
		for (int i=n-1; i>=2; --i) 
			for (int j=i-1; j>=1; --j) {
				if (i == n-1) dp[i][j] = dist[i][n]+dist[j][n];
				else dp[i][j] = min(dp[i+1][j]+dist[i][i+1], dp[i+1][i]+dist[j][i+1]);
			}
			
		printf("%.2f\n", dp[2][1]+dist[1][2]);
	}
	return 0;
} 
