#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

const int maxn = 1000+5;

struct Particle{
	int x,y;
	int r;  /* 1 is hydrophobic 
			*   0 is hydrophilic */
	double rad; 
	bool operator<(const Particle& rhs) const {
		return this->rad < rhs.rad;
	}
}pacs[maxn], polar[maxn];

int n;

inline
bool left(const Particle& p1, const Particle& p2){
	return p1.x*p2.y-p1.y*p2.x >= 0;
}
int solve(){
	int L,R;
	int maxsum=0;
	int index=0;
	int ans=0;
	for(int i=0; i<n; ++i){
		
		index=0;
		for(int j=0; j<n; ++j){
			if(i!=j){
				polar[index].x=pacs[j].x-pacs[i].x;
				polar[index].y=pacs[j].y-pacs[i].y;
				if(pacs[j].r) {
					polar[index].x=-polar[index].x;
					polar[index].y=-polar[index].y;
				} 
				polar[index++].rad=atan2(polar[index].y,polar[index].x);
			}
		}
		sort(polar,polar+index);
		
		L=0;R=0;maxsum=2;
		while(L<index){  //try all possible cases
			//roll a entire circle 
			if(L==R){R=(R+1)%index; maxsum++;}
			while(L!=R&&left(polar[L],polar[R])){
				R=(R+1)%index; maxsum++;
			}
			maxsum--;L++;
			
			ans=ans>maxsum?ans:maxsum;
		}
	}
	
	return ans;
}

int main(void){
	while(cin>>n&&n){
		for(int i=0; i<n; ++i){
			cin>>pacs[i].x>>pacs[i].y>>pacs[i].r;
			pacs[i].rad=0.0;
		}
		
		printf("%d\n",solve());
	}		
	return 0;
} 
