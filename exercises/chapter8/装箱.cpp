/*
* Created by LeoChen008
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 100000+5;
int L[maxn];
int maxl;
int n;

int main(void){
	int T;
	int ans;
	cin >> T;
	while(T--) {
		cin >> n; cin  >> maxl;
		for(int i=0; i<n; ++i) cin >> L[i];
		sort(L,L+n);
		
		ans = 0;
		int low = 0;
		int high = n-1;
		while (low <= high) {
			if(L[low] + L[high] <= maxl) {
				low++;high--;
				ans++;
			}
			else {
				high--;
				ans++;
			}
		}
		printf("%d\n",ans);
		if(T>0) printf("\n");
	}
	return 0;
}
