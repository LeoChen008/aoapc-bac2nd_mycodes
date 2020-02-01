/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 100000+5;
const double eps = 1e-9;

struct Intval{
	int bg,end;
	
	bool operator< (const Intval& rhs) const {
		return this->bg < rhs.bg;
	}
		
}a[maxn];

int n;
 
inline 
bool judge(long double mid) {
	long double cur = 0;
	for (int i=0; i<n; ++i) {
		cur = max(cur, (long double)a[i].bg) + mid;
		if (cur > (long double)a[i].end) return false;
	}
	
	return true;
}
int main(void)
{
	long double L,R,mid,ans;
	while (cin >> n) {
		for (int i=0; i<n; ++i) {
			cin >> a[i].bg >> a[i].end;
		}
		
		sort(a, a+n);
		
		L = 0, R = 1000000;
		while (R - L > eps) {
			mid = L + (R - L)/2.0;
			if (judge(mid)) L = mid;
			else R = mid;
 		}
 		
 		ans = L;
 		int fp = 0, fq = 1;
 		for (int p,q = 1; q<=n; ++q) {
 			p = round(ans * q);
 			if (fabs(ans - 1.0*p/q) < fabs(ans - 1.0*fp/fq)) {
 				fp = p; fq = q;
			 }
		}
		
		printf("%d/%d\n", fp,fq); 
	}
	
	return 0;
}
