#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

const int maxn=24;
typedef int State[maxn];

State states[1000000];
vector<int> ans;
vector< vector<int> > step(1000000);
set<int> vis_a;
set<int> vis_b;
set<int> vis_c;
set<int> vis_d; 

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

bool isfinal(int *b,int target){
	
	for(int i=0;i<8;i++){
		if(b[center[i]]!=target){
			return false;
		}
	}
	
	return true; 
}

void move(int *b,int dir){
	int temp=b[pieces[dir][0]];
	
	for(int i=1;i<7;i++){
		b[pieces[dir][i-1]]=b[pieces[dir][i]];
	}
	b[pieces[dir][6]]=temp;
}

void init_st(){
	//初始化查找表
	vis_a.clear();
	vis_b.clear();
	vis_c.clear();
	vis_d.clear();
}
bool try_insert_st(int *b){
	//尝试插入查找表
	bool flag=false;
	int va,vb,vc,vd;
	va=vb=vc=vd=0;
	
	for(int i=0;i<7;i++){
		va=va*10+b[pieces[0][i]];
		vb=vb*10+b[pieces[1][i]];
		vc=vc*10+b[pieces[2][i]];
		vd=vd*10+b[pieces[3][i]];
	}
	
	if(!vis_a.count(va)){
		vis_a.insert(va);
		flag=true;
	}
	else if(!vis_b.count(vb)){
		vis_b.insert(vb);
		flag=true;
	}
	else if(!vis_c.count(vc)){
		vis_c.insert(vc);
		flag=true;
	}
	else if(!vis_d.count(vd)){
		vis_d.insert(vd);
		flag=true;
	}
	
	return flag;
}
bool bfs(int *b,int target){
	init_st();
	int front=1,rear=2;
	memcpy(states[1],b,sizeof(int)*maxn);
	
	while(front<rear){
		State& t=states[front];		
		if(isfinal(t,target)){
			ans=step[front];
			return true;
		}
		
		State& next=states[rear];
		for(int i=0;i<8;i++){
			memcpy(next,t,sizeof(t));
			move(next,i);
			if(try_insert_st(next)){
				step[rear]=step[front];
				step[rear].push_back(i);
				rear++;
			}
		}
		
		front++;
	}
	
	return false;	
}

int main(void){
	int t;
	State board;
	int tar; 
	vector<int> a;
	while(cin>>t&&t){
		
		board[0]=t;
		for(int i=1;i<maxn;i++){
			cin>>board[i];
		}
		
		if(isfinal(board,1)||isfinal(board,2)||isfinal(board,3)){
			printf("No moves needed\n");
			continue;
		}
		
		if(bfs(board,2)){
			a=ans;
			tar=2;
		}
		if(bfs(board,1)){
			if(a.size()>ans.size()){
				a=ans;
				tar=1;
			}
		}
		if(bfs(board,3)){
			if(a.size()>ans.size()){
				a=ans;
				tar=3;
			}
		}
		
		for(int i=0;i<a.size();i++){
			printf("%c",a[i]+'A');
		}
		printf("\n%d\n",tar);
		
	}
} 
