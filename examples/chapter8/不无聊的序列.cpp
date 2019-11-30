/*
* Created by LeoChen008
*/
#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

const int maxn = 200000 + 5;
int n;
int seq[maxn];
int pre[maxn],nex[maxn];
map<int, int> m;

inline 
bool unique(int i, int L, int R){
	return pre[i]<L && (nex[i]>R || nex[i]==i); 
}
bool check_unq(int left, int right) {
	if(left >= right) return true;
	
	int unq = 0;
	while(left+unq <= right-unq) {
		if(unique(left+unq, left, right)) 
			return check_unq(left,left+unq-1) && check_unq(left+unq+1,right);
		if(unique(right-unq, left, right))
			return check_unq(left,right-unq-1) && check_unq(right-unq+1,right);
		unq++;
	}
	
	return false;
}
int main(void){
	int T;
	cin >> T;
	while(T--) {
		cin >> n;
		m.clear(); 
		for(int i=0; i<n; ++i) {
			cin >> seq[i]; 
			if(!m.count(seq[i])) pre[i] = -1;
			else pre[i] = m[seq[i]];
			m[seq[i]] = i;
		}
		
		for(int i=n-1; i>=0; --i) {
		    nex[i] = m[seq[i]];
			m[seq[i]] = i;
		}
		
		if(check_unq(0, n-1)) printf("non-boring\n");
		else printf("boring\n"); 
	} 
	return 0;
} 
