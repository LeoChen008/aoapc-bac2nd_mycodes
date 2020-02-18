/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100+5;
struct Tree{
	int x,y;
	bool operator< (const Tree& rhs) const{
		return this->x < rhs.x || 
		(this->x == rhs.x && this->y < rhs.y) ;	
	}
}trees[maxn];
int n,w,h;
int dy[maxn];
int kcase = 0; 
int main(void)
{
	int T;
	cin >> T;
	getchar();
	while (T--) {
		cin >> n >> w >> h;
		for (int i=1; i<=n; ++i) {
			cin >> trees[i].x >> trees[i].y;
			dy[i] = trees[i].y;
		}
		dy[0] = 0; dy[n+1] = h;
		sort(dy+1, dy+n+1);
		sort(trees+1, trees+n+1);
		
		if (kcase++) printf("\n");
		
		
		int y1, y2;
		int temp, tempx;
		int len;
		int ans = 0, x, y;
		for (int i=0; i<=n+1; ++i) {
			y1 = dy[i];
			for (int j=i+1; j<=n+1; ++j) {
				y2 = dy[j];
				len = y2 - y1;
				temp = 0; 
				if (y2 == y1) continue;
				if (i && y1 == dy[i-1]) continue;
				if (y2 == dy[j-1]) continue;
				
				for (int k=1; k<=n; ++k) {
					if (trees[k].y <= y1 || trees[k].y >= y2) continue;
					tempx = trees[k].x - temp;
					if (ans < min(len, tempx)) {
						ans = min(len, tempx);
						x = temp; y = y1;
					}  
					temp = trees[k].x;
				}
				
				if (ans < min(len, w-temp)){
					ans = min(len, w-temp);
					x = temp; y=y1;
				}
			}
		}
		
		printf("%d %d %d\n", x, y, ans); 
	}
	
	return 0;
}
