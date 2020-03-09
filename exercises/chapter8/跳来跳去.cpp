/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long LL;
LL a,b,c;
LL pos;

inline
void move_next(int len) {
	pos += len;
	printf(" %lld", pos);
}
int main(void) {
	int T;
	while(cin >> T && T) {
		while (T--) {
			cin >> a >> b >> c;

			pos = 0;

			printf("0");

			if (c%3 == 0) {
				move_next(2);
				for (int i=0; i<c/3; ++i)move_next(3);
				move_next(-1);
				for (int i=0; i<c/3; ++i)move_next(-3);
				move_next(2);
				for (int i=0; i<c/3; ++i)move_next(3);

				a-=1;
				b-=2;
			} else if (c%3 == 1) {
				for (int i=0; i<c/3+1; ++i) move_next(3);
				move_next(-2);
				for (int i=0; i<c/3; ++i) move_next(-3);
				move_next(1);
				for (int i=0; i<c/3; ++i) move_next(3);
				move_next(2);

				a-=1;
				b-=2;
			} else if (c%3 == 2) {
				for (int i=0; i<c/3+1; ++i) move_next(3);
				move_next(-1);
				for (int i=0; i<c/3; ++i)   move_next(-3);
				move_next(-1);
				for (int i=0; i<c/3+1; ++i) move_next(3);

				a-=2;
			}

			for (int i=0; i<a-1; ++i) move_next(1);

			for (int i=0; i<ceil(b/2.0); ++i) move_next(2);
			move_next(b%2==0 ? 1:-1);
			for (int i=0; i<b/2; ++i) move_next(-2);

			printf("\n");
		}
	}
	return 0;
}
