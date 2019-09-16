#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxr=5;
const int maxc=9;
int edge[9][8]={{1,3,9,13,18,19,21,22}};
int inner[9][4]={{10,11,12,20}};
#define Loop_edge(i) for(int i=0;i<8;i++)
#define Loop_inner(i) for(int i=0;i<4;i++)
#define _DEBUG
int maze[maxr][maxc];
int m[maxr*maxc];
int bits[maxc];

void pretreat(){
	//预处理：将所有正方形可能出现的位置记录
	int dir=2;
	for(int i=1;i<9;i++){
		if(i%3==0) dir=5;
		else dir=2; 
		
		for(int j=0;j<8;j++){
			if(j<4){
				inner[i][j]=inner[i-1][j]+dir;
			}
			edge[i][j]=edge[i-1][j]+dir;
		}
	}
}
int bitpos(int on){
	int count=0;
	for(int i=0;i<9;i++){
		if((1<<i)&on){
			bits[count++]=i;
		}
	}
	return count;
}
bool judge(){
	for(int i=0;i<maxr;i++){
		for(int j=0;j<maxc;j++){
			if(maze[i][j]!=m[i*9+j]) return false;
		}
	}
	return true;
}
char* solve(){
	char* ans=new char;
	int num;
	for(int i=0;i<(1<<9);i++){
		num=bitpos(i);
		if(num>6||num<1) continue;
		
		memset(m,0,sizeof(m));
		
		do{
			for(int j=0;j<num;j++){
				Loop_edge(a) m[edge[bits[j]][a]]=1;
				Loop_inner(b) m[inner[bits[j]][b]]=0;
			}
			if(judge()){
				ans="Yes";
				return ans;
			}
		}while(next_permutation(bits,bits+num));
		
	}
	ans="No";
	return ans;
}
int main(void){
	#ifdef DEBUG
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int kcase=0;
	string buffer;
	
	pretreat(); 
	
	while(getline(cin,buffer)&&buffer[0]!='0'){
		memset(maze,0,sizeof(maze)); 
		for(int i=0;i<maxr;i++){
			if(i) getline(cin,buffer);
			for(int j=0;j<maxc;j++){
				if(buffer[j]=='_'||buffer[j]=='|'){
					maze[i][j]=1;
				}
			}
		}
		
		printf("Case %d: %s\n",++kcase,solve());
	}
	fclose(stdin);
	fclose(stdout);
} 
