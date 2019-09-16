#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
using namespace std;
const int maxn=100;
int n;
vector<int> pile[maxn];
void find_pile(int a,int &p,int &h){
	for(p=0;p<n;p++){
		for(h=0;h<pile[p].size();h++){
			if(pile[p][h]==a) return;
		}
	}
}
void clear_above(int p,int h){
	for(int i=h+1;i<pile[p].size();i++){
		int t=pile[p][i];
		pile[t].push_back(t);
	}
	pile[p].resize(h+1);
}
void pile_onto(int pa,int ha,int pb){
	for(int i=ha;i<pile[pa].size();i++){
		int t=pile[pa][i];
		pile[pb].push_back(t);
	}
	pile[pa].resize(ha);
}
void print(){
	for(int i=0;i<n;i++){
		printf("%d:",i);
		for(int j=0;j<pile[i].size();j++){
			printf(" %d",pile[i][j]);
		}
		printf("\n");
	}
}
int main(void){
	int a,b;
	string cm1,cm2;
	cin>>n;
	for(int i=0;i<n;i++)pile[i].push_back(i);
	while(cin>>cm1&&cm1!="quit"){
		cin>>a>>cm2>>b; 
		int pa,pb,ha,hb;
		find_pile(a,pa,ha);
		find_pile(b,pb,hb);
		if(pa==pb) continue;
		if(cm1=="move")clear_above(pa,ha);
		if(cm2=="onto")clear_above(pb,hb);
		pile_onto(pa,ha,pb);
	}
	print();
} 
