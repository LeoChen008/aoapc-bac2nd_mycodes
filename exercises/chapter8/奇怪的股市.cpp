/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100000+5;
 
int a[maxn];
int b[maxn];
int n;

bool cmp(int i, int j) {
	return a[i] > a[j];
}
int main(void)
{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	long long sum;
	while( cin >> n ) {
		sum = 0;
		for (int i=0; i<n; ++i) {
			cin >> a[i];
			sum += a[i];
			b[i] = i;
		}
		
		if(sum & 1) {printf("No\n");continue;}
		
		sort(b, b+n, cmp);
		
		int temp = sum >> 1;
		for (int i=0; i<n; ++i) {
			
			if (temp >= a[b[i]]) {
				temp -= a[b[i]];
				a[b[i]] = 1; 
			}
			else a[b[i]] = -1;   
		}
		
		printf("Yes\n");
		for (int i=0; i<n-1; ++i) printf("%d ", a[i]);
		printf("%d\n", a[n-1]); 
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
