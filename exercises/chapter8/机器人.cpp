/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>
#include <cmath> 
#include <algorithm>
using namespace std;

typedef long long LL;

int kcase = 0;
LL ans;

inline
LL solve(LL rows, LL cols, LL n, LL s, LL w, LL e) 
{
	
	LL res = 0;
	if (s > n) swap(s,n);
	if (e > w) swap(e,w);
	
	if (w) {
		res += rows * cols;
		cols--; w -= e;
		if (w) { res += rows*cols*e*2; w--;}
		else res += rows*cols*(e*2 - 1);
		e = 0;
	}
	
	if (n) {
		n -= s;
		if (n) {s = s*2; n--;}
		else s = s*2 - 1; 
		while ( (rows-1)*s*2 <= cols - rows && w) {
			res += rows * cols;
			w--; cols--;
		}
		res += rows * cols; rows--;
		res += rows * cols * s; 
		s = 0;
	} 
	
	while (n + w > 0 && cols && rows) {
		res += rows * cols;
		if ( cols > rows && w ) { cols--; w--;}
		else if (!n) { cols--; w--;}
		else { rows--; n--;}
	}
	
	return res;
}
int main(void)
{
	int N,M;
	int n,s,w,e;
	while (cin >> N >> M && N) {
		cin >> n >> s >> w >> e;
		ans = max(solve(N,M,n,s,w,e), solve(M,N,w,e,s,n));
		printf("Case %d: %lld\n", ++kcase, ans);	
	}
	return 0;
}
