#include<iostream>
#include<cstring>
using namespace std;

const int maxn=1<<10;
string s;

struct Node{
	char ch;
	Node *p[4];
	Node(){
		ch='';
		memset(p,0,sizeof(p));
	} 
};
void build(const string s,Node *n){
	//
}
int main(void){
	int T;
	cin>>T;
	while(T--){
		Node *root=new Node(); 
		getline(cin,s);
		build(s,root);
		getline(cin,s);
		build(s,root);
	}
}
