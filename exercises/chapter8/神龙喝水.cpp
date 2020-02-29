/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int maxn = 1e6+5;
int lastday[maxn];
int used[maxn];
vector<int> norains;
set<int> s;
int n,m;
int main(void)
{
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		
		bool flag = true;
		fill(lastday+1, lastday+n+1, 0);
		norains.clear(); s.clear();
		
		int lake;		
		for (int i=1; i<=m; ++i) {
			cin >> lake;
			
			if (lake != 0) {
				
				set<int>::const_iterator iter = s.lower_bound(lastday[lake]);
				if(iter != s.end()){
					used[*iter] = lake;
					lastday[lake] = i;
					s.erase(iter);
				}else {
					flag = false;
				}
			}else {
				norains.push_back(i);
				used[i] = 0;
				s.insert(i);
			}
			
			if (!flag) for (;i<m;++i) cin >> lake;
		}
		
		if (!flag)  printf("NO\n");
		else {
			printf("YES\n");
			int len = norains.size();
			for (int i=0; i<len-1; ++i) printf("%d ", used[norains[i]]);
			printf("%d\n", used[norains[len-1]]); 
		}
		
	}
	return 0;
} 
