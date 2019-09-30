#include<iostream>
#include<cstdio> 
#include<cstring> 
#include<cmath>
using namespace std;

const int maxn =7+5;
const int palace[4]={1,4,3,6};
const int dx[4]={0,-1,0,1};
const int dy[4]={-1,0,1,0};
const int dhx[8]={1,-1,-2,-2,1,-1,2,2};
const int dhy[8]={-2,-2,-1,1,2,2,-1,1};

int board[15][14];
int bx,by; //black general position 
int n;
struct Piece{
	int x,y;
	char type;
}p[maxn]; 

bool parse_general(Piece p,int x,int y){
	
	int start,end;
	if(y==p.y){
		
		for(int i=x+1;i<p.x;i++){//cannot fly over interverning pieces
			if(board[i][y]){
				return false;
			}
		}
		
		return true; //flying general
	}
	return false;
}
bool parse_chariot(Piece p,int x,int y){
	
	if(x==p.x&&y==p.y) return false;
	
	int start,end;
	if(x==p.x){
		if(y>p.y){
			start=p.y;end=y;
		}else{
			start=y;end=p.y;
		}		
		
		for(int i=start+1;i<end;i++){
			if(board[x][i]){
				return false;
			}	
		}
		
		return true;
	}
	else if(y==p.y){
		if(x>p.x){
			start=p.x;end=x;
		}else{
			start=x;end=p.x;
		} 
		
		for(int i=start+1;i<end;i++){
			if(board[i][y]){
				return false;
			}
		}
		
		return true;
	}
	
	return false;
}
bool parse_horse(Piece p,int x,int y){
	if(x==p.x&&p.y==y) return false;
	
	int x1=p.x;
	int y1=p.y;
	int x2,y2;
	for(int i=0;i<8;i++){
		x2=x1+dhx[i];
		y2=y1+dhy[i];
		if(x2==x&&y2==y){
			if(abs(dhx[i])==2&&board[x1+dhx[i]/2][y1]){
				return false;
			}
			else if(abs(dhy[i])==2&&board[x1][y1+dhy[i]/2]){
				return false;
			}
			
			return true;
		}
	}
	
	return false;
}
bool parse_cannon(Piece p,int x,int y){
	if(x==p.x&&y==p.y){
		return false;
	}
	int cnt=0;
	int start,end;
	if(x==p.x){
		if(y>p.y){
			start=p.y;end=y;
		}else{
			start=y;end=p.y;
		}		
		
		for(int i=start+1;i<end;i++){
			if(board[x][i]){
				cnt++;
			}	
		}
		
		if(cnt>1||cnt==0) return false; 
		
		return true;
	}
	else if(y==p.y){
		if(x>p.x){
			start=p.x;end=x;
		}else{
			start=x;end=p.x;
		} 
		
		for(int i=start+1;i<end;i++){
			if(board[i][y]){
				cnt++;
			}
		}
		
		if(cnt>1||cnt==0) return false;
		
		return true;
	} 
	
	return false;
}
bool parse_piece(Piece p,int x,int y){
	bool flag=false;
	switch(p.type){
		case 'G': flag=parse_general(p,x,y);break;
		case 'R': flag=parse_chariot(p,x,y);break;
		case 'H': flag=parse_horse(p,x,y);break;
		case 'C': flag=parse_cannon(p,x,y);break;
	}
	
	return flag;
}
bool solve(const int x,const int y){
	
	int x2,y2;
	bool flag=false;
	
	for(int i=0;i<4;i++){  //4 directions to move
		x2=x+dx[i];
		y2=y+dy[i];
		
		if(x2<palace[0]||x2>palace[2]||y2<palace[1]||y2>palace[3]) continue;
		
		for(int j=0;j<n;j++){ // n black pieces
			flag=parse_piece(p[j],x2,y2);
			
			if(flag) break; // if p[j] can capture bg within one step
		}
		if(!flag) return true;//fail to checkmate
	}
	
	return false; //achieve checkmate
}
int main(void){
	
	bool flag=false;
	while(cin>>n&&n){
		cin>>bx>>by;
		
		memset(board,0,sizeof(board));
		 
		for(int i=0;i<n;i++){
			cin>>p[i].type>>p[i].x>>p[i].y;
			board[p[i].x][p[i].y]=1;
		}
		cin.get();
		
		flag=false;
		for(int i=0;i<n;i++){//check whether bg and rg are face to face
			if(p[i].type=='G'){
				flag=parse_general(p[i],bx,by);
				break;
			}
		}
		
		if(flag){
			printf("NO\n");
		}
		else if(solve(bx,by)){
			printf("NO\n");
		}
		else printf("YES\n");
	}
}
