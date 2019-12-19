/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 10000+5;
int a[maxn],p[maxn];
int n;
vector< pair<int,int> > ans;

inline
void swap_order(int left, int right) 
{
	int mid = left + (right - left)/2; 
	for (int i=left; i<=mid; ++i) {
		swap(a[i], a[mid + i-left + 1]);
	}
	
	ans.push_back(make_pair(left,right));
}
int main(void)
{
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i=1; i<=n; ++i) { cin >> a[i]; p[a[i]]=i;}
		
		int pos;
		ans.clear();
		for (int i=1; i<=n; ++i) {
			if (a[i] == i) continue;
			
			pos = find(a, a+n, i) - a;
			while (a[i] != i) {
				if (n - pos + 1 >= pos - i) swap_order(i, 2*(pos-i)+i-1);
				else {
					if(pos - i + 1 & 1) swap_order(i+1, pos);
					else swap_order(i, pos);
					pos -= (pos-i+1)/2;
				}
			}
			
		}
		
		printf("%d\n", ans.size());
		for(int i=0; i<ans.size(); ++i) printf("%d %d\n", ans[i].first, ans[i].second); 
	} 
	return 0;	
} 
