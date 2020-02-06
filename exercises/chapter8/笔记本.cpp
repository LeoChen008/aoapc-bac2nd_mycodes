/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100000+5;

struct Task{
	int r,d;
	bool operator< (const Task& rhs) const {
		return this->d < rhs.d || (this->d == rhs.d && this->r < rhs.r);
	}
}task[maxn];
int n;
int main(void)
{
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i=0; i<n; ++i) {
			cin >> task[i].r >> task[i].d;
		}
		
		sort(task, task+n);
		
		int ans = 0;
		int pos = task[0].d;
		for (int i=1; i<n; ++i) {
			if (pos == task[i].d) continue;
			else if(pos < task[i].r) {
				ans++;
				pos = task[i].d;
			}  
			else pos++;
		}
		
		printf("%d\n", ans); 
	} 
	return 0;
}
