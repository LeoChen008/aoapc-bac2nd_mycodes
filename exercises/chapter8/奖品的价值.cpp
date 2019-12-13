/*
* Created by LeoChen008
*/
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

const int maxn = 100000+5;

int main(void)
{
	int n,d;
	string s;
	string ans;
	while (cin >> n >> d && n && d)
	{
		cin >> s;
		
		ans = "";
		int temp, start = 0;
		int maxnum;
		int maxindex;
		while (start + d + 1 <= n) 
		{	
			maxindex = start;
			maxnum = s[maxindex] - '0';
			for(int i=start; i<start+d+1; ++i) {
				temp = s[i] - '0';
				if (temp > maxnum) {
					maxnum = temp;
					maxindex = i;
				}
			}
			
			d -= maxindex - start;
			start = maxindex + 1;
			ans.push_back(s[maxindex]);
		}
		
		cout << ans << endl;
	} 
	return 0;
}
