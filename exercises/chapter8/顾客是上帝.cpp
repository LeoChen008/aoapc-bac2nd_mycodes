/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = 800000+5;

struct Order{
	int q,d;
	Order(int q=0, int d=0):q(q),d(d){} 
	
	bool operator< (const Order& rhs) const{
		return this->d < rhs.d;
	}
}orders[maxn];

int n;
priority_queue<int> q;
int main(void)
{
	int T;
	int kcase = 0;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i=0; i<n; ++i) {
			cin >> orders[i].q >> orders[i].d; 
		}
		sort(orders, orders+n);
		
		while(!q.empty()) q.pop(); 
		int time = 0;
		int temp;
		for (int i=0; i<n; ++i) {
			if (time + orders[i].q <= orders[i].d) {
				time += orders[i].q;
				q.push(orders[i].q);
			}
			else if (!q.empty()){
				temp = q.top();
				if (temp > orders[i].q) {
					time -= (temp - orders[i].q);
					q.pop();
					q.push(orders[i].q);
				}
			}
		}
		
		if(kcase++) printf("\n");
		printf("%d\n", q.size());
	} 
	return 0;
}

