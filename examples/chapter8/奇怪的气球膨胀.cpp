/*
* Created by LeoChen008
*/
#include<iostream>
#include<cstdio>

using namespace std;

typedef long long LL;

inline 
LL tot(int k){ 
	return k == 0 ? 1 : tot(k-1)*3;
}
LL above_red(int k, int row){
	if(row==0) return 0;
	if(k==0) return 1; 
	
	int row2 = 1 << (k-1);
	if(row >= row2) return above_red(k-1,row-row2) + tot(k-1)*2;
	 return above_red(k-1,row)*2;
}
int main(void) {
	int T;
	int K,A,B;
	int kcase = 0;
	
	cin >> T;
	while(T--) {
		cin >> K >> A >> B;
		printf("Case %d: %lld\n",++kcase,above_red(K,B)-above_red(K,A-1));		
	}
	
}
