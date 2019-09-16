#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const int maxn=5000;

struct Node{
	Node *L,*R;
	bool has_valued;
	int val;
	Node():has_valued(false),L(NULL),R(NULL){}
};

Node *root;   //根节点 
char s[maxn]; //保存输入的结点 
bool failed;  // 判断是否 有重复的结点 



/*
**删除二叉树
**释放内存空间 
*/
void remove_tree(Node *n){
	if(n==NULL) return;
	remove_tree(n->L);
	remove_tree(n->R);
	delete n;
}

/*
**创建新节点并返回指针 
*/
Node* newnode(){
	return new Node();
}

/*
**addnode()创建树并检测
**是否有重复的结点 
*/
void addnode(int v,char *s){
	int n=strlen(s);
	Node *u=root;
	for(int i=0;i<n;i++){
		if(s[i]=='L'){
			if(u->L==NULL) u->L=newnode();
			u=u->L;
		}else if(s[i]=='R'){
			if(u->R==NULL) u->R=newnode();
			u=u->R;
		}
	}
	if(u->has_valued){
		failed=true;
	}
	u->val=v;
	u->has_valued=true;
}
/*
**raw_input()是将屏幕输入的字符存储在s中 
**并实现创建节点和检测 
*/
bool raw_input(){
	failed=false;
	remove_tree(root);
    root=newnode();
	while(true){
		if(scanf("%s",s)!=1) return false;
		if(!strcmp(s,"()")) break;
		int v;
		sscanf(&s[1],"%d",&v);
		addnode(v,strchr(s,',')+1);
	}
	return true;	
}

/*
**bfs()用来进行层次遍历二叉树，
**并将结点值按层次遍历存储在 
**ans 连表中，并检测是否有未被
**赋值的节点。 
*/
bool bfs(vector<int>& ans){
	queue<Node*> q;
	ans.clear();
	q.push(root);
	while(!q.empty()){
		Node *u=q.front();q.pop();
		if(!u->has_valued) return false;
		else{
			ans.push_back(u->val);
			if(u->L!=NULL) q.push(u->L);
			if(u->R!=NULL) q.push(u->R);
		}
	}
	return true;
}


int main(void){
	vector<int> ans;
	
	while(raw_input()){
		if(bfs(ans)&&!failed){
			int len=ans.size();
	        for(int i=0;i<len-1;i++){
		         printf("%d ",ans[i]);
    	    } 
    	    printf("%d\n",ans[len-1]);
		}else{
			printf("not complete\n");
		}
		
	} 
}
