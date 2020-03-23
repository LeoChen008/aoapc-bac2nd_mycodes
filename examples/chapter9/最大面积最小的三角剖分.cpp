/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int maxm   = 50+5;
const int inf    = 0x3f3f3f3f;
const double esp = 1e-10;
struct Node{
	double x,y;
	Node (double x=0.0, double y=0.0):x(x), y(y){}
}nodes[maxm];
double dp[maxm][maxm];
int m;

inline
double get_area(int i, int j, int k)
{
	return fabs((nodes[j].x - nodes[i].x) * (nodes[k].y - nodes[i].y) 
				- (nodes[j].y - nodes[i].y) * (nodes[k].x - nodes[i].x))/2.0;
}

bool judge(int i, int j, int k)
{
	double s;
	for (int p=0; p<m; ++p) {
		if (p == i || p == j || p == k) continue;
		s = get_area(p, i, j) + get_area(p, i, k) + get_area(p, j, k);
		if (fabs(s-get_area(i,j,k)) < esp) return true; 
	}
	
	return false;
}
double solve()
{
	int ed;
	for (int len=1; len<m; ++len) {
		for (int st=0; st+len<m; ++st) {
			ed = st+len;
			if (len == 1) dp[st][ed] = 0;
			else {
				dp[st][ed] = inf;
				for (int k=st+1; k<ed; ++k) {
					if (judge(st, ed, k)) continue;
					double temp = max(dp[st][k], dp[k][ed]);
					temp = max(temp, get_area(st, ed, k));
					dp[st][ed] = min(dp[st][ed], temp); 
				}
			}
		}
	}	
	return dp[0][m-1]; 
}
int main(void)
{
	int T;
	cin >> T;
	while (T--) {
		cin >> m;
		for (int i=0; i<m; ++i) cin >> nodes[i].x >> nodes[i].y;
		
		printf("%.1lf\n", solve());				
	}
	return 0;
}
