/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 500+5;
int a[maxn];
int n;
int main(void)
{
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i=0; i<n; ++i) {
			cin >> a[i];
		}
		
		int cnt = 0;
		for (int i=0; i<n-1; ++i) {
			for (int j=i+1; j<n; ++j) {
				if (a[i] > a[j]) cnt++;
			}
		}
		
		if (n%2 && cnt%2) printf("impossible\n");
		else printf("possible\n");
		
	} 
	return 0;
}
