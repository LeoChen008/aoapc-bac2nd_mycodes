/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 100000+5;

int N;
int p[maxn];
int q[maxn];

inline
int judge(int start) {
	int pertol = p[start] - q[start];
	for(int i=start+1; i!=start; i=(i+1)%N){
		if(pertol >= 0) pertol += p[i] - q[i];
		else return i;
	}
	
	if(pertol < 0) return -1;
	return start;
}
int main(void) {
	int T,ans;
	int kcase=0;
	cin >> T;
	while(T--){
		cin >> N;
		for(int i=0; i<N; ++i) cin >> p[i];
		for(int i=0; i<N; ++i) cin >> q[i];
		
		int start=0;
		int temp;
		ans=-1;
		while(true) {
			temp = judge(start);
			if(temp==start){
				ans = start + 1;
				break;
			}
			else if(temp > start){
				start = temp;
			}
			else break;
		}
		
		if(ans != -1) printf("Case %d: Possible from station %d\n",++kcase,ans);
		else printf("Case %d: Not possible\n",++kcase);
	}
	return 0;	
} 
