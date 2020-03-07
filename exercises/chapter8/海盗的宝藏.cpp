/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long LL;
const int maxn = 500+5;
const int inf = 0x3f3f3f3f;
int rect[maxn][maxn];
int L[maxn], R[maxn];
int stak[maxn], dep[maxn];
int a,b,m,n;
LL vol;

inline
LL cal(LL x, LL y, LL d)
{
	LL h = (m*n*d - 1)/(m*n - x*y);
	return x*y*h;
}
int main(void) {
	while( cin >> a >> b >> m >> n && a) {

		for (int i=1; i<=m; ++i) {
			for (int j=1; j<=n; ++j) {
				cin >> rect[i][j];
			}
		}

		if (a > b) swap(a,b);
		vol = 0;
		int top = 0;
		stak[0] = 0; stak[n+1] = 0;
		for (int x=1; x<=m; ++x) {
			for (int y=1; y<=b&&y<=m-x+1; ++y) {
				if (y == 1) for (int i=1; i<=n; ++i) dep[i] = inf;
				for (int i=1; i<=n; ++i) dep[i] = min(rect[x+y-1][i], dep[i]);

				for (int i=1; i<=n; ++i) {
					while (top && dep[i] < dep[stak[top]]) R[stak[top--]] = i;
					L[i] = stak[top] + 1;
					stak[++top] = i; 
				}
				
				while(top) R[stak[top--]] = n+1;
				for (int i=1; i<=n; ++i) 
					vol = max(vol, cal(min(y>a?a:b, R[i]-L[i]),y,dep[i]));
			}

		}
		
		printf("%lld\n", vol);
	}

	return 0;
}
