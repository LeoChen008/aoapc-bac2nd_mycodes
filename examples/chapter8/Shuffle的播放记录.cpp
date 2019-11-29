/*
* Created by LeoChen008
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 100000+5;
int s,n;
int records[maxn*3];
int flag[maxn];
int cnt[maxn];

void init() {
	fill(cnt+1, cnt+s+1, 0);
	fill(flag, flag+s+n+1, 0);

	int sum = 0;
	for(int i=0; i<=n+s; ++i) {
		if(sum == s) flag[i] = 1;
		if(sum == i && i <= s-1) flag[i] = 1;
		if(sum == s+n-i && i >= n-1) flag[i] = 1;
		
		
		if(i == n+s) break;
		if(records[i] != -1 && --cnt[records[i]]==0) sum--;
		if(records[i+s] != -1 && cnt[records[i+s]]++==0) sum++;
	}
}
int main(void) {
	int T;
	cin >> T;
	while(T--) {
		cin >> s >> n;

		fill(records, records+n+s*2, -1);
		for(int i=0; i<n; ++i) cin >> records[i+s];
		
		init();
		
		int ans = 0;
		bool check = true;
		for(int i=0; i<s; ++i){
			check = true;
			for(int j=i; j<=n+s; j+=s){
				if(!flag[j]){
					check = false;
					break;
				}
			}
			
			if(check) ans++;
		}
		
		printf("%d\n",ans==n+1?s:ans);
	}
	return 0;
}
