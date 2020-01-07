/*
* Created by LeoChen008
*/
#include <iostream>
#include <vector>
#include <algorithm> 
#include <cstdio>
#include <cmath> 

using namespace std;


struct Sec{
	double l,r;
	Sec(double l=0, double r=0):l(l),r(r){}
	
	bool operator<(const Sec& rhs) const{
		return this->r < rhs.r;
	} 
};

vector<Sec> s;
int line;
int d,n;

inline
void get_pos(double &l,double &r,double x,double y) {
	r = x + sqrt( (double)(d*d) - y*y );
	l = x - sqrt( (double)(d*d) - y*y );
}
int main(void)
{
	double x,y;
	double l,r;
	int ans;
	while (cin >> line) {
		cin >> d >> n;
		
		s.clear();
		for (int i=0; i<n; ++i) {
			cin >> x >> y;
			get_pos(l,r,x,y);
			s.push_back(Sec(max(0.0, l),min((double)line, r)));
		}
		
		sort(s.begin(), s.end());
		
		ans = 0;
		double pos = -1.0;
		for (int i=0; i<n; ++i) {
			if (s[i].l > pos || s[i].r < pos) {
				ans++;
				pos = s[i].r;
			}
		}
		
		printf("%d\n", ans);
	}		
	return 0;
}
