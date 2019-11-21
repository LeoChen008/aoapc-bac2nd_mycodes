/*
* Created by LeoChen008
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long LL;
const int maxm = 500+5;
int m,k;
int p[maxm];
int flag[maxm];

inline
int judge(LL maxs) {
	int scrs = 1;
	LL presum = 0;
	for(int i=0; i<m; ++i) {
		if(presum + p[i] <= maxs) presum += p[i];
		else {
			scrs++;
			presum = p[i];
		}
	}
	return scrs;
}
void solve(int low, LL high) {
	LL mid = 0;
	while(low < high) {
		mid = low + (high - low)/2;
		if(judge(mid) <= k) high = mid;
		else low = mid + 1;
	}

	LL maxs = low;
	LL presum = 0;
	int remain = k;
	memset(flag, 0, sizeof(flag));

	for(int i=m-1; i>=0; --i) {
		if(presum + p[i] > maxs || i+1 < remain) {
			remain--;
			presum = p[i];
			flag[i] = 1;
		} else {
			presum += p[i];
		}
	}

	for(int i=0; i<m-1; ++i) {
		printf("%d ",p[i]);
		if(flag[i]) printf("/ ");
	}
	printf("%d\n", p[m-1]);
}
int main(void) {
	int T;
	int maxp,low;
	LL sum,high,mid;
	cin >> T;
	while (T--) {
		cin >> m >>k;

		sum=0;
		maxp=0;
		for(int i=0; i<m; ++i) {
			cin >> p[i];
			sum += p[i];
			maxp = max(maxp,p[i]);
		}

		solve(maxp,sum);
	}
	return 0;
}
