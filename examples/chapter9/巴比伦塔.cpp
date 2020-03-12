/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 30+5;

struct Block{
	int size[3];
}bl[maxn]; 

int dp[maxn][3];  // stand for the highest height at certain top block and its height
int n;

inline
void get_other_dmen(int* ptr, int b, int h)
{
	int id = 0;
	for (int j=0; j<3; ++j){
		if (j != h) ptr[id++] = bl[b].size[j]; 
	}
}
int solve(int a, int b)
{
	int& ans = dp[a][b];
	if (ans > 0) return ans;  // avoid for extra computation
	
	int v[2],v1[2];
	get_other_dmen(v, a, b);
	for (int i=0; i<n; ++i) 
		for (int j=0; j<3; ++j) {
			get_other_dmen(v1, i, j);
			if (v[0] < v1[0] && v[1] < v1[1])
				ans = max(ans, solve(i, j));
		}
		
	ans += bl[a].size[b];
	return ans;
} 
int main(void)
{
	int kcase = 0;
	while (cin >> n && n) {
		for (int i=0; i<n; ++i) {
			cin >> bl[i].size[0] >> bl[i].size[1] >> bl[i].size[2];
			sort(bl[i].size, bl[i].size+3);
		}
		
		memset(dp, 0, sizeof(dp));
		int ans = 0;
		for (int i=0; i<n; ++i)
			for (int j=0; j<3; ++j)
				ans = max(ans, solve(i,j));
		printf("Case %d: maximum height = %d\n", ++kcase, ans);
	}
	return 0; 
} 
