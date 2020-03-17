/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1000+5;

char str[maxn];
int dp[maxn];  // dp[i] stand for the minimum numbers of palindrome sequences from 0-i
int len;

inline
int judge_pald(int st, int ed) 
{ 
	int slen = ed - st + 1;
	while (st < ed) {
		if (str[st] != str[ed]) return 0;
		st++; ed--;
	}
	return 1;
}
int main(void)
{
	int T;
	cin >> T;
	while (T--) {
		scanf("%s", str+1);
		len = strlen(str+1);
		
		dp[0] = 0;
		for (int i=1; i<=len; ++i) {
			dp[i] = i+1;
			for (int j=0; j<i; ++j) {
				if (judge_pald(j+1, i))
					dp[i] = min(dp[i], dp[j] + 1);
			}
		}
		
		printf("%d\n", dp[len]);
	}
	return 0;
} 
