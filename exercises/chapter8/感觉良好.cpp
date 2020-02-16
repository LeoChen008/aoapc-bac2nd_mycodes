/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 100000+5;
int a[maxn];
long long sum[maxn];
int l[maxn],r[maxn];
int n;

int main(void)
{	
	int kcase = 0;
	while (cin >> n && n) {
		sum[0] = 0; a[0] = -1; a[n+1] = -1;
		
		if (kcase++) printf("\n");
		for (int i=1; i<=n; ++i) {
			cin >> a[i];
			sum[i] = sum[i-1] + a[i];
			l[i] = i; r[i] = i;
		}
		
		for (int i=1; i<=n; ++i) {
			while(a[i] <= a[l[i]-1]) l[i] = l[l[i]-1];
		}
		
		for (int i=n; i>=1; --i) {
			while(a[i] <= a[r[i]+1]) r[i] = r[r[i]+1];
		}
		
		
		long long ans = a[1]*a[1], temp;
		int L=1,R=1;
		for (int i=1; i<=n; ++i) {
			temp = (sum[r[i]] - sum[l[i]] + a[l[i]])*a[i];
			if (temp > ans) {
				ans = temp;
				L = l[i];
				R = r[i];
			}
		}
		
		printf("%lld\n", ans);
		printf("%d %d\n", L, R);
	}
	return 0; 
}
