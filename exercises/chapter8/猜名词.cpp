/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 16384+5;

struct Player{
	int score[8];
}P[maxn];

int R[maxn]; 
int n;
int main(void) 
{
//	freopen("in.txt", "r", stdin); 
//	freopen("out.txt", "w", stdout); 
	int kcase = 0;
	double temp[3]; 
	while (cin >> n && n) {
		for (int i=1; i<=n; ++i) {
			cin >> temp[0] >> temp[1] >> temp[2];
			
			for (int j=0; j<8; ++j) {
				P[i].score[j] = 0;
				for (int k=0; k<3; ++k) {
					if ( j & (1 << k) ) P[i].score[j] += (int)(round(temp[k]*100));
				} 
			}
			
			sort(P[i].score, P[i].score+8);
		}
		
		for(int i=1; i<=n; ++i) {
			cin >> R[i];
		}
		
		int max = P[R[1]].score[7];
		int id = R[1];
		int i;
		for (i=2; i<=n; ++i) {
			
			int cur = R[i];
			bool flag = false;
			for (int j=7; j>=0; --j) {
				if (P[cur].score[j] == max && cur > id) {
					flag = true;
					id = cur;
					break;
				}
				else if (P[cur].score[j] < max) {
					flag = true;
					max = P[cur].score[j];
					id = cur;
					break;
				}
			}
			
			if (!flag) break; 
		}
		
		printf("Case %d: ", ++kcase);
		if (i!=n+1) printf("No solution\n");
		else {
			printf("%.2f\n",max/100.0);
		}		
	}
	return 0;	
} 
