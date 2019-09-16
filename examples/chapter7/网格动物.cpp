#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
using namespace std;

const int maxn=10;
const int dy[]={0,0,1,-1};
const int dx[]={1,-1,0,0};

int ans[maxn+1][maxn+1][maxn+1];

struct Cell{
	int x,y;
	Cell(int x=0,int y=0):x(x),y(y){}
	bool operator<(const Cell &c) const{
		return x<c.x||(x==c.x&&y<c.y);
	}
};
typedef set<Cell> Poly;
#define FOR_CELL(c,p) for(Poly::iterator c=(p).begin();c!=(p).end();c++)

set<Poly> s[maxn+1];

inline int getcounts(int n,int w,int h){
	int minX=10000,minY=10000,maxX=-1,maxY=-1;
	int count=0;
	for(set<Poly>::iterator iter=s[n].begin();iter!=s[n].end();iter++){
		maxX=-1;
		maxY=-1;
		FOR_CELL(c,*iter){
			maxX=max(maxX,c->x);
			maxY=max(maxY,c->y);
		}
		if(min(maxX,maxY)<min(h,w)&&max(maxX,maxY)<max(h,w)){
			count++;
		}
	}
	
	return count;
}

inline Poly normalize(const Poly &p){
	int minX=p.begin()->x;
	int minY=p.begin()->y;
	
	FOR_CELL(c,p){
		minX=min(minX,c->x);
		minY=min(minY,c->y);
	}
	
	Poly p2;
	FOR_CELL(c,p){
		p2.insert(Cell(c->x-minX,c->y-minY));
	}
	
	return p2;	
}
inline Poly check_rotate(const Poly &p){
	Poly p2;
	FOR_CELL(c,p){
		p2.insert(Cell(c->y,-c->x));
	}
	
	return normalize(p2);
} 
inline Poly flip(const Poly &p){
	Poly p2;
	FOR_CELL(c,p){
		p2.insert(Cell(c->x,-c->y));
	}
	
	return normalize(p2);
}

void check_in(const Poly &p,const Cell &c){
	Poly p1=p;
	p1.insert(c);
	p1=normalize(p1);
	
	int size=p1.size();
	
	for(int i=0;i<4;i++){
		if(s[size].count(p1)!=0) return;
		p1=check_rotate(p1);
	}
	
	p1=flip(p1);
	
	for(int i=0;i<4;i++){
		if(s[size].count(p1)!=0) return;
		p1=check_rotate(p1);
	}
	
	s[size].insert(p1);
}

void solve(){
	Cell start;
	Poly p;
	p.insert(start);
	s[1].insert(p);
	
	//generate all different size of polyominoes
	for(int i=2;i<=maxn;i++){
		set<Poly> &st=s[i-1];
		for(set<Poly>::iterator iter1=st.begin();iter1!=st.end();iter1++){
			FOR_CELL(c,*iter1){
				int xx,yy;
				for(int dir=0;dir<4;dir++){
					xx=c->x+dx[dir];
					yy=c->y+dy[dir];
					
					Cell next(xx,yy); 
					if(iter1->count(next)==0) check_in(*iter1,next);
				}
			}
		}
	}
	
	
	//compute the sum of polyominoes that can fit in all different size of mazes
	for(int n=1;n<=maxn;n++){
		for(int w=1;w<=maxn;w++){
			for(int h=1;h<=maxn;h++){
				ans[n][w][h]=getcounts(n,w,h);
			}
		}
	}
}

int main(void){
	solve();	
	int n,w,h;
	while(cin>>n>>w>>h){
		printf("%d\n",ans[n][w][h]);
	}
} 

