/*
* Created by LeoChen008
*/
#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
using namespace std;

const int maxn = 1024+5;
int n;
int a[maxn][maxn];
vector<int> win,lose;

int main(void) {
	string str;
	while(cin >> n) {
		win.clear();
		lose.clear();
		for(int i=1; i<=n; ++i) {
			cin >> str;
			for(int j=0; j<n; ++j) {
				a[i][j+1] = str[j]-'0';
				if(i == 1 && j+1 > 1 && a[i][j+1]) win.push_back(j+1);
				else if(i == 1 && j+1 > 1 && !a[i][j+1]) lose.push_back(j+1); 
			}
		}
		
		int round = n;
		while(round > 1) {
			
			vector<int> win2, lose2, final;
			bool flag = false;
			
			//part1
			for(int i=0; i<lose.size(); ++i) {
				int r1 = lose[i];
				flag = false;
				for(int j=0; j<win.size(); ++j) {
					int& r2 = win[j];
					if(r2 > 0 && a[r2][r1]) {
						printf("%d %d\n",r2,r1);
						win2.push_back(r2);
						flag = true;
						r2 = 0;
						break;
					}
				}
				
				if(!flag) final.push_back(r1); 
			}
			
			//part2
			bool first = true;
			for(int i=0; i<win.size(); ++i) {
				int r1 = win[i];
				if(r1 > 0){
					if(first) { printf("1 %d\n",r1);first = false;}
					else final.push_back(r1);
				}
			}
			
			//part3
			for(int i=0; i<final.size(); i+=2) {
				printf("%d %d\n",final[i],final[i+1]);
				int temp = final[i];
				if(a[final[i+1]][final[i]]) temp = final[i+1];
				if(a[1][temp]) win2.push_back(temp);
				else lose2.push_back(temp);
			
			}
			win = win2;
			lose = lose2;
			round = round >> 1;
		}
	}	
	return 0;
}
