/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 1000+5;
string names[maxn];
int n;
int main(void) 
{
	while(cin >> n && n) {
		for(int i=0; i<n; ++i) cin >> names[i];
		sort(names, names+n);
		
		string L,R;
		string temp;
		string ans = "";
		L = names[n/2-1];
		R = names[n/2];
		
		int len = 1;
		int Llen = L.length();
		int Rlen = R.length();
		while(len <= Llen && len <= Rlen) 
		{
			temp = L.substr(0, len);
			if (temp == R.substr(0, len)) {
				ans = temp;
				len++; 
			}
			else {
				if(len == Llen) {
					ans.push_back(L[len-1]);
				}
				else if (R[len-1] - L[len-1] > 1 || len < Rlen) {
					ans.push_back(L[len-1]+1);
				}
				else if(len == Rlen) {
					ans.push_back(L[len-1]);
					for(int i=len; i<Llen; ++i){
						if(i == Llen-1) {
							ans.push_back(L[i]);break;
						}
						else if(L[i] != 'Z') {
							ans.push_back(L[i]+1);break;
						}
						ans.push_back('Z');
					}
				}
				
				break;
			}
		}
		cout << ans <<endl;		
	}	
	return 0;	
} 
