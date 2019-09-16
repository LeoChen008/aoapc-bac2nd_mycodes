#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define DEBUG
const int maxn=15+5;
const int maxs=1000000;
typedef int Path[2];

int h;				//initial empty hole
int ans;
int board[maxn][7]; //6 direction connection status
int stats[maxs]; 
int dist[maxs];
int fa[maxs]; 
Path path[maxs];
int vis[1<<maxn];
 
void pre_set(){
	board[1][1]=-1; board[1][2]=-1; board[1][3]=-1; board[1][4]=-1; board[1][5]=2;  board[1][6]=3;
	board[2][1]=-1; board[2][2]=1;  board[2][3]=-1; board[2][4]=3;  board[2][5]=4;  board[2][6]=5;
	board[3][1]=1;  board[3][2]=-1; board[3][3]=2;  board[3][4]=-1; board[3][5]=5;  board[3][6]=6;
	board[4][1]=-1; board[4][2]=2;  board[4][3]=-1; board[4][4]=5;  board[4][5]=7;  board[4][6]=8;
	board[5][1]=2;  board[5][2]=3;  board[5][3]=4;  board[5][4]=6;  board[5][5]=8;  board[5][6]=9;
	board[6][1]=3;  board[6][2]=-1; board[6][3]=5;  board[6][4]=-1; board[6][5]=9;  board[6][6]=10;
	board[7][1]=-1; board[7][2]=4;  board[7][3]=-1; board[7][4]=8;  board[7][5]=11; board[7][6]=12;
	board[8][1]=4;  board[8][2]=5;  board[8][3]=7;  board[8][4]=9;  board[8][5]=12; board[8][6]=13;
	board[9][1]=5;  board[9][2]=6;  board[9][3]=8;  board[9][4]=10; board[9][5]=13; board[9][6]=14;
	board[10][1]=6; board[10][2]=-1;board[10][3]=9; board[10][4]=-1;board[10][5]=14;board[10][6]=15;
	board[11][1]=-1;board[11][2]=7; board[11][3]=-1;board[11][4]=12;board[11][5]=-1;board[11][6]=-1;
	board[12][1]=7; board[12][2]=8; board[12][3]=11;board[12][4]=13;board[12][5]=-1;board[12][6]=-1;
	board[13][1]=8; board[13][2]=9; board[13][3]=12;board[13][4]=14;board[13][5]=-1;board[13][6]=-1;
	board[14][1]=9; board[14][2]=10;board[14][3]=13;board[14][4]=15;board[14][5]=-1;board[14][6]=-1;
	board[15][1]=10;board[15][2]=-1;board[15][3]=14;board[15][4]=-1;board[15][5]=-1;board[15][6]=-1;
}

inline bool judge(int a){
	if(!(a&1<<h)){
		for(int i=1;i<=15;i++){
			if(i!=h&&!(a&1<<i)) return false;
		}
	}
	else return false;
	
	return true;
}
void solve(){
	int rear,front;
	front=1;rear=2;
	while(front<rear){
		int stat=stats[front];
		if(judge(stat)){
			ans=front;
			return;
		}
		for(int i=1;i<=15;i++){
			if(stat&(1<<i)) continue;
			for(int j=1;j<=6;j++){
				if(board[i][j]==-1||(stat&1<<board[i][j])) continue;
				int next=board[i][j];
				if(board[next][j]==-1) continue;
				int temp=stat;
				while(next!=-1&&!(stat&1<<next)){
					temp^=1<<next;
					next=board[next][j];
				}
				if(next==-1) continue;
				
				temp^=1<<i|1<<next;
				stats[rear]=temp;
				dist[rear]=dist[front]+1;
				fa[rear]=front;
				path[rear][0]=i;
				path[rear][1]=next;
				if(!vis[temp]){
					vis[temp]=1;
					rear++;
				}
			}
		}
		front++;
	}
}
void print_path(int cur){
	if(cur==1) return;
	print_path(fa[cur]);
	printf("%d %d%c",path[cur][0],path[cur][1],cur==ans?'\n':' ');  
}
int main(void){
	#ifdef _DEBUG
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	pre_set();
	int T;
	cin>>T;
	while(T--){
		memset(vis,0,sizeof(vis));
		stats[1]=0;
		dist[1]=0;
		ans=-1;
		cin>>h;
		stats[1]|=1<<h;
		solve();
		if(ans==-1) printf("IMPOSSIBLE\n");
		else{
			printf("%d\n",dist[ans]);
			print_path(ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
} 
