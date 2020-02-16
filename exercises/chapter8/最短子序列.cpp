/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace  std;

const int maxn = 1000000+5;
const int maxm = 1000+5;
int seq[maxn];
int cnt[maxm];
int n,m,k;
int kcase = 0;

inline
bool judge(int len) {
	int tot=0;
	memset(cnt, 0, sizeof(int)*(k+1));
	for(int i=0; i<=n; ++i) {
		if (tot==k) return true;
		if (i==n) break;
		if (seq[i] <= k && cnt[seq[i]]++ == 0) tot++;
		if (i>=len && seq[i-len] <=k && --cnt[seq[i-len]] == 0) tot--;
	}
	return false;
}
int main(void)
{
	int T;
	cin >> T;
	seq[0] = 1; seq[1] = 2; seq[2] = 3;
	while (T--) {
		cin >> n >> m >> k;
		for (int i=3; i<n; ++i){
			seq[i] = (seq[i-1]+seq[i-2]+seq[i-3])%m + 1;
		}
		
		int low = k, high = n, mid;
		while(low <= high) {
			mid = low + (high-low)/2;
			if (judge(mid)) high = mid - 1;
			else low = mid + 1;
		}
		
		if (judge(low)) printf("Case %d: %d\n", ++kcase, low);
		else printf("Case %d: sequence nai\n",++kcase);
	} 
	return 0;
}
