#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream> 

using namespace std;

const int maxn=26+5;

string preorder;
string inorder;
char postorder[maxn];


void solve(int inbg,int ined,int prebg,int posted){
	if(inbg>=ined) return;
	
	int root;
	for(int i=inbg;i<ined;i++){
		if(inorder[i]==preorder[prebg]){
			root=i;
		}
	}
	
	solve(inbg,root,prebg+1,posted-(ined-root));
	solve(root+1,ined,prebg+root-inbg+1,posted-1);
	
	postorder[posted]=inorder[root];
}
int main(void){
	while(cin>>preorder>>inorder){
		int len=preorder.length();

		solve(0,len,0,len-1);
		
		for(int i=0;i<len;i++){
			printf("%c",postorder[i]);
		}
		
		printf("\n");
	}
}
