/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring> 
using namespace std;

const int maxn = 500+5;

int a[maxn],b[maxn];
int pos[maxn],pos2[maxn]; 
int n;

int solve(int start, int d) {
	
	int count = 0;
	for (int i=0; i<n; ++i) {
		if (start != b[i]) {
			b[pos2[start]] = b[i];
			pos2[b[i]] = pos2[start];
			
			b[i] = start;
			pos2[start] = i;
			count++;
		}
		
		start = (start + d + n)%n;
	}
	
	return count;
}
int main(void) 
{
	while (cin >> n && n) {
		for (int i=0; i<n; ++i) {
			cin >> a[i];
			a[i]--;
			pos[a[i]] = i;
		}
		
		int ans = 0x3f3f3f3f;
		for (int k=1; k>=-1; k-=2) {
			for (int i=0; i<n; ++i) {
				memcpy(b, a, sizeof(int)*n);
			    memcpy(pos2, pos, sizeof(int)*n);
				ans = min(ans, solve(i,k));
			}
		}
		
		printf("%d\n", ans);		
	}
	return 0;	
} 
