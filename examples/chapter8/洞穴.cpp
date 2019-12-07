/*
* Created by LeoChen008
*/
#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int maxn = 1000000 + 5;
int n;
int p[maxn];
int s[maxn];
int level[maxn]; 

int main(void){	
	int T;
	int ans;
	cin >> T;
	while(T--) {
		cin >> n;
		for (int i=0; i<n; ++i) cin >> p[i];
		for (int i=0; i<n; ++i) cin >> s[i];
		ans = 0;
		
		fill(level, level+n, -1);
		
		int maxh = s[0];
		for(int i=0; i<n; ++i) {
			if(maxh < p[i]) maxh = p[i];
			if(maxh > s[i]) maxh = s[i];
			level[i] = maxh;
		}
		
		maxh = s[n-1];
		for(int i=n-1; i>=0; --i) {
			if(maxh < p[i]) maxh = p[i];
			if(maxh > s[i]) maxh = s[i];
			ans += min(maxh,level[i]) - p[i];
		}
		
		printf("%d\n",ans);
	} 
	return 0;
} 
