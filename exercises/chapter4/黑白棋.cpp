#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define FOR_BOARD() for(int r=1;r<=8;r++)for(int c=1;c<=8;c++) 
const int maxn = 8+5;
const int dx[8]={0,-1,-1,-1,0,1,1,1};
const int dy[8]={-1,-1,0,1,1,1,0,-1};
const char disk[2]={'W','B'};

char board[maxn][maxn];
int legals[2][maxn][maxn];
int bw=-1; // current player 1--black 0--white

inline void change_disk(int x,int y,int dir){
	if(bw==-1) return;
	
	int rn=x+dx[dir],cn=y+dy[dir];
	
	while(board[rn][cn]!=disk[bw]){
		board[rn][cn]=disk[bw];
		rn+=dx[dir];
		cn+=dy[dir];
	}
}
inline bool brackted(int x,int y,int dir){
	int rn=x,cn=y;
	bool credge=false;
	
	while(board[rn][cn]!=disk[bw]){
		rn+=dx[dir];
		cn+=dy[dir];
		if(rn<1||rn>8||cn<1||cn>8){
			credge=true;break;
		}
		if(board[rn][cn]=='-')break;
	}
	
	if(!credge&&board[rn][cn]==disk[bw]) return true;
	
	return false;
}
void find_legal(){
	if(bw==-1) return;
	
	int rn,cn,rp,cp;
	memset(legals,0,sizeof(legals));
	FOR_BOARD(){
		if(board[r][c]!=disk[bw]&&board[r][c]!='-')
			for(int dir=0;dir<8;dir++){
				rn=r+dx[dir];rp=r-dx[dir];
				cn=c+dy[dir];cp=c-dy[dir];
				
				if(rp<1||rp>8||cp<1||cp>8||board[rp][cp]!='-') continue;
				if(rn<1||rn>8||cn<1||cn>8) continue;
				if(board[rn][cn]=='-') continue;
				
				if(brackted(rn,cn,dir)){
					legals[bw][r-dx[dir]][c-dy[dir]]+=1<<dir;
				}
			}
	}
}
void list_legal(){
	if(bw==-1) return;
	int count=0;
	 
	FOR_BOARD(){
		if(legals[bw][r][c]){
			if(count++) printf(" "); 
			printf("(%d,%d)",r,c);
		}
	}
	if(!count) printf("No legal move.\n");
	else printf("\n");
}
void print_board(){
	for(int i=1;i<=8;i++){
		for(int j=1;j<=8;j++){
			cout<<board[i][j];
		}
		cout<<endl;
	}
}
void print_number(){
	int b,w;
	b=w=0;
	FOR_BOARD(){
		if(board[r][c]=='B') b++;
		else if(board[r][c]=='W') w++;
	}
	printf("Black -%3d White -%3d\n",b,w); 
}
int main(void){
	int T,kcase=0;
	string cmod; 
	cin>>T;
	while(kcase<T){
		getchar();
		for(int i=1;i<=8;i++){
			for(int j=1;j<=8;j++){
				scanf("%c",&board[i][j]);
			}
			getchar();
		}
		
		
		bw=-1;
		
		if(kcase++)printf("\n");
		int x,y;
		int dirs;
		while(cin>>cmod){
			if(cmod[0]=='W')     {bw=0;find_legal();}
			else if(cmod[0]=='B'){bw=1;find_legal();}
			else if(cmod[0]=='Q'){print_board();break;}
			else if(cmod[0]=='L'){list_legal();}
			else if(cmod[0]=='M'){
				x=cmod[1]-'0';y=cmod[2]-'0';
				dirs=legals[bw][x][y];
				
				if(dirs&255){      
					board[x][y]=disk[bw];
				}
				else{
					bw^=1;
					find_legal();
					dirs=legals[bw][x][y];
					board[x][y]=disk[bw];
				}
				
				for(int rshift=0;rshift<8;rshift++) 
					if((dirs>>rshift)&1){
						change_disk(x,y,rshift);
					}
				bw^=1;
				find_legal();
				print_number();
			}
		}
	}
} 
