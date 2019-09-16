#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int maxn=24;
const int maxm=1000;

int board[maxn];
int step[maxm];

int pieces[8][7]={
	{0,2,6,11,15,20,22},  //A
	{1,3,8,12,17,21,23},  //B
	{10,9,8,7,6,5,4},     //C
	{19,18,17,16,15,14,13}, //D
	{23,21,17,12,8,3,1},  //E
	{22,20,15,11,6,2,0}, //F
	{13,14,15,16,17,18,19}, //G
	{4,5,6,7,8,9,10}, //H
};	

int rev[8]={5,4,7,6,1,0,3,2};
int center[8]={
	6,7,8,
	11,12,
	15,16,17
};

bool isfinal(){
	for(int i=0;i<8;i++){
		if(board[center[i]]!=board[center[0]]) return false;
	}
	return true;
}


void move(int *b,int dir){
	int temp=b[pieces[dir][0]];
	for(int i=1;i<7;i++) b[pieces[dir][i-1]]=b[pieces[dir][i]];
	b[pieces[dir][6]]=temp;
}


int diff(int tar){
	int count=0;
	for(int i=0;i<8;i++){
		if(board[center[i]]!=tar) count++;
	}
	return count;
}
int h(){
	return min(min(diff(1),diff(2)),diff(3));
}

bool dfs(int cur,int maxd){
	if(isfinal()){
		for(int i=0;i<cur;i++){
			printf("%c",step[i]+'A');
		}
		printf("\n");
		return true;
	}
	if(cur+h()>maxd) return false;
	
	for(int i=0;i<8;i++){
		step[cur]=i;
		move(board,i);
		if(dfs(cur+1,maxd)) return true;
		move(board,rev[i]);
	}
	
	return false;
}
int main(void){
	int t;
	int maxd;
	while(cin>>t&&t){
		board[0]=t;
		for(int i=1;i<maxn;i++) cin>>board[i];
		
		if(isfinal()){
			printf("No moves needed\n");
		}else{
			for(maxd=1;;maxd++){
				if(dfs(0,maxd)) break; 
			}
		}
		printf("%d\n",board[center[0]]);
	}
}
