#include<iostream>
#include<string>
#include<sstream>
#include<cstdlib>
#include<cstring>
using namespace std;

const int maxn=10000+10;

int postorder[maxn];
int inorder[maxn];
int r[maxn],l[maxn];
int nodes[maxn]; 
int len;
int sum=0,minsum=100000000;
bool raw_input(int *a){
	string s;
	if(!getline(cin,s)){
		return false;
	}
	stringstream ss;
	ss<<s;
	len=0;
	int x;
	while(ss>>x) a[len++]=x;
	
	return len>0;
}
int build(int L1,int R1,int L2,int R2){
	if(L1>R1) {
		return 0;
	}
	int root=postorder[R2];
	sum+=root;
	int index=L1;
	while(inorder[index]!=root) index++;
	
	int LL1=index-L1;
	l[root]=build(L1,index-1,L2,L2+LL1-1);
	r[root]=build(index+1,R1,L2+LL1,R2-1);
	
	if(!l[root]&&!r[root]){
	    minsum= sum<minsum ?sum:minsum;
	    nodes[root]=sum;
	}
	sum-=root;
	return root;
}
int best_node(){
	for(int i=0;i<maxn;i++){
		if(nodes[i]==minsum) return i;
	}
	return -1;
}
int main(void){
	while(raw_input(inorder)){
		raw_input(postorder);
		memset(nodes,0,sizeof(nodes));
		minsum=100000000;
		build(0,len-1,0,len-1);
		printf("%d\n",best_node());
	}
}
