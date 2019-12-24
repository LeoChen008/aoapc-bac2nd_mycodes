/*
* Created by LeoChen008
*/
#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 300+5;
int a[maxn];
int n;

inline 
bool ifsorted(int *x)
{
	for(int i=0; i<n-1; ++i) {
		if(x[i] > x[i+1]) return false;
	}
	return true;
}
int main(void)
{ 
	string ans;
	
	while (cin >> n && n) {
		for(int i=0; i<n; ++i) {
			cin >> a[i];
		}
		
		ans = "";
		
		if( ifsorted(a) ) {
			printf("\n");
			continue;
		}
		
		while ( !ifsorted(a) ) {
			if( a[0] != n && a[0] > a[1]) {
				ans.push_back('1');
				swap(a[0],a[1]);
			}
			
			if( ifsorted(a) ) break;
			
			ans.push_back('2');
			int temp = a[n-1];
			for (int i=n-1; i>0; --i) {
				a[i] = a[i-1];
			}
			a[0] = temp;
		}
		
		for(int i=ans.length()-1; i>=0; --i) printf("%c",ans[i]);
		printf("\n");
	} 
	return 0;	
} 
