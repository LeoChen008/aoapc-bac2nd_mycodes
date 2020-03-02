/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int maxd = 2*1000+5;

int LH[maxd], RH[maxd];
int ans;
int main(void)
{
	int left, right;
	int lmaxi, rmaxi;
	while (cin >> left >> right && left && right){
 		int lmax, rmax;
 		lmax = rmax = 0;
		for (int i=-left; i>0; i-=2) {
			cin >> LH[i];
			if (lmax <= LH[i]) { lmax = LH[i]; lmaxi = i;}
		}
		for (int i=1; i<=right; i+=2) {
			cin >> RH[i];
			if (rmax < RH[i]) { rmax = RH[i]; rmaxi = i;}
		}
		
		ans = 0;
		int Lv, Rv, h;
		Lv = Rv = 0;
		
		if (lmax == rmax) {
			ans += rmax*(rmaxi + lmaxi);
			for (int i=-left, h=LH[i]; i>lmaxi; i-=2) {
				if (h < LH[i]) {Lv += LH[i]*2; h = LH[i];}
				else Lv += h*2;
			}
			for (int i=right, h=RH[i]; i>rmaxi; i-=2) {
				if (h < RH[i]) {Rv += RH[i]*2; h = RH[i];}
				else Rv += h*2;
			}
			ans += min(Lv, Rv) * 2;
		}
		else if (lmax < rmax) {
			int ri = 1;
			while (ri < right && RH[ri] < lmax) ri+=2;
			
			for (int i=-left, h=LH[i]; i>lmaxi; i-=2) {
				if (h < LH[i]) {Lv += LH[i]*2; h = LH[i];}
				else Lv += h*2;
			}
			
			if (RH[ri] == lmax) {
				for (int i=ri; RH[i]<=lmax; i+=2)  Rv += 2*lmax;
				
				ans += (ri + lmaxi)*lmax;
				ans += Lv > Rv ? Lv+Rv : Lv*2;
			}
			else 
				ans += Lv + (ri + lmaxi)*lmax;
		}
		else {
			int li = 1;
			while (li < -left && LH[li] < rmax) li+=2;
			
			for (int i=right, h=RH[i]; i>rmaxi; i-=2) {
				if (h < RH[i]) {Rv += RH[i]*2; h = RH[i];}
				else Rv += h*2;
			}
			
			if (LH[li] == rmax) {
				for (int i=li; LH[i]<=rmax; i+=2)  Lv += 2*rmax;
				
				ans += (li + rmaxi)*rmax;
				ans += Rv > Lv ? Lv+Rv : Rv*2;
			}
			else 
				ans += Rv + (li + rmaxi)*rmax;
		}
		
		printf("%d\n", ans);
	}
	return 0;
} 
