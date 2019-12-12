/*
* Created by LeoChen008
*/
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

/**
*	cnt[0] <==> 1-->0
*	cnt[1] <==> 0-->1
* 	cnt[2] <==> ?-->0
*	cnt[3] <==> ?-->1
*/
int cnt[4];
int main(void) 
{
	int C;
	cin >> C;
	string S,T;
	for(int kcase=1; kcase<=C; ++kcase) 
	{
		cin >> S;cin >> T;
		
		memset(cnt, 0, sizeof(cnt));
		int len = S.length();
		for(int i=0; i<len; ++i) {
			if(S[i] == '1' && T[i] == '0') cnt[0]++;
			else if(S[i] == '0' && T[i] == '1') cnt[1]++;
			else if(S[i] == '?' && T[i] == '0') cnt[2]++;
			else if(S[i] == '?' && T[i] == '1') cnt[3]++;			 
		} 
		
		int step = 0;
		if(cnt[1] + cnt[3] < cnt[0]) {printf("Case %d: -1\n",kcase);continue;}
		else if (cnt[0] - cnt[1] <= 0) {
			step += cnt[0]; cnt[1] -= cnt[0];
			step += cnt[1];
			step += cnt[2] + cnt[3]; 
		}
		else if (cnt[0] - cnt[1] > 0) {
			step += cnt[1]; cnt[0] -= cnt[1];
			step += cnt[0]*2; cnt[3] -= cnt[0];
			step += cnt[3] + cnt[2];
		}
		
		printf("Case %d: %d\n",kcase, step);
	} 
	return 0; 
}
