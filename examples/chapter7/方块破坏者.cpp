#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int maxs=55+5;//The maxium number of squares
const int maxm=60;//2*5*(5+1) The maxium number of matchsticks  

int n,len,s;
int ans;
int sticks[maxm];        
int squares[maxs][maxm];   
int size[maxs];
int fullsize[maxs];

inline int match_count(int m){
	//Get the number of sticks by square's side length 
	return 2*m*(m+1);
}
inline int get_id(int x,int y,int type){
	return type==1?(2*n+1)*x+y+1:(2*n+1)*x+n+y+1;
}

void dfs(int cur){
	if(cur>=ans) return;
	
	int sq=-1;
	for(int i=s-1;i>=0;i--){
		if(size[i]==fullsize[i]){
			sq=i;
			break;
		} 
	}
	if(sq==-1){
		ans=cur;
		return;
	}
	
	for(int i=1;i<=match_count(n);i++){
		if(squares[sq][i]){
			for(int j=s-1;j>=0;j--){
				if(squares[j][i]) size[j]--;
			}
			dfs(cur+1);
			for(int j=s-1;j>=0;j--){
				if(squares[j][i]) size[j]++;
			}
		}
	}
	
}
int solve(){
    ans=maxm;
	
	dfs(0);
	
	return ans;
}

int main(void){
	int T;
	cin>>T;
	while(T--){
		cin>>n>>len;
		
		
		for(int i=1;i<=match_count(n);i++) sticks[i]=1;		
		
		for(int i=0;i<len;i++){
			int j;
			cin>>j;
			sticks[j]=0;
		}
		
		memset(squares,0,sizeof(squares));
		
		s=0;
		for(int i=1;i<=n;i++){
			for(int x=0;x<=n-i;x++){
				for(int y=0;y<=n-i;y++){
					size[s]=0;
					fullsize[s]=4*i;
					for(int j=0;j<i;j++){
						int u0=get_id(x,y+j,1);
						int d0=get_id(x+i,y+j,1);
						int l0=get_id(x+j,y,0);
						int r0=get_id(x+j,y+i,0);
						
						squares[s][u0]=1;
						squares[s][d0]=1;
						squares[s][l0]=1;
						squares[s][r0]=1;
						
						size[s]+=sticks[u0]+sticks[l0]+sticks[r0]+sticks[d0];
					}
					
					s++;
				}
			}
		}
		
		printf("%d\n",solve());
	}
} 
