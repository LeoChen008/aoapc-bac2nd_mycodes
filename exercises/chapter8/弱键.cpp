/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 5000+5;
int seq[maxn];
int n;
vector< pair<int, int> > a;
bool solve() {
	bool flag = false;
	a.clear();
	for (int i=1; i<n-2; ++i) {
		for (int j=i+1; j<n-1; ++j) {
			if (seq[i] > seq[j]) {
				a.push_back(make_pair(i,j));
			}
		}
	}

	pair<int, int> temp;
	int q,r,s;
	for (int i=0; i<a.size(); ++i) {
		temp = a[i];
		q = temp.first;
		r = temp.second;
		s = n;
		for (int j=r+1; j<n; ++j) {
			if (seq[j] < seq[q] && seq[j] > seq[r] && seq[s] < seq[j]) {
				s = j;
			}
		}

		if (s==n) continue;

		for (int j=0; j<q; ++j) {
			if (seq[j] < seq[s] && seq[j] > seq[r]) {
				flag = true;
				break;
			}
		}
	}


	return flag;
}
int main(void) {
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i=0; i<n; ++i) {
			cin >> seq[i];
		}
		seq[n] = -1;

		if (solve()) {
			printf("YES\n");
			continue;
		} else reverse(seq, seq+n);

		if (solve()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;

}
