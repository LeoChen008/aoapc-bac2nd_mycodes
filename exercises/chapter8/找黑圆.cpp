/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 100+5;
const double pi = 3.1415926535;
int image[maxn][maxn];
int w,h;

struct Circle {
	int r,x,y;
	Circle (int r,int x,int y):r(r),x(x),y(y) {}
	bool operator< (const Circle& rhs) const {
		if (this->r != rhs.r) return this->r < rhs.r;
		if (this->x != rhs.x) return this->x < rhs.x;
		return this->y < rhs.y;
	}
};
vector<Circle> ans;

int main(void) {
	int T;
	int kcase = 0;
	cin >> T;
	while (T--) {
		cin >> w >> h;
		char ch;
		for (int i=0; i<h; ++i) {
			for (int j=0; j<w; ++j) {
				cin >> ch;
				image[i][j] = ch - '0';
			}
		}

		ans.clear();
		int x,y;
		int cnt;
		for (int r=5; r<50; ++r) {
			for (int i=r; i<h-r+1; ++i) {
				for (int j=r; j<w-r+1; ++j) {
					cnt = 0;
					for (double angle = -pi/2.0; angle <= pi/2.0; angle += 0.1) {
						x = int(j+r*cos(angle)+0.5);
						y = int(i-r*sin(angle)+0.5);
						if (x >= w || x < 0 || y < 0 || y >= h) continue;
						if (image[y][x] && image[y][2*j-x]) cnt++;

						if(angle > 0.0 && cnt < int(pi/4.0*10)) break;
					}

					if (cnt > int((pi/2.0+0.5)*10)) ans.push_back(Circle(r,j,i));
				}
			}
		}

		sort(ans.begin(), ans.end());

		printf("Case %d: %d", ++kcase, ans.size());
		for (int i=0; i<ans.size(); ++i)
			printf(" (%d,%d,%d)", ans[i].r,ans[i].x,ans[i].y);
		printf("\n");
	}
	return 0;
}
