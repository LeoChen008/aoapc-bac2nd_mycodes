#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

const int maxn=50; 
const int maxm=100000;

int kcase=0;
vector<int> temp[3];

struct Node{
	int index;
	bool has_value; 
	Node *next[10];
}; 

Node *root; 

Node* givenode(){
	Node* temp=new Node();
	temp->index=0;
	for(int i=0;i<10;i++){
		temp->next[i]=NULL;
	}
	temp->has_value=false;
	
	return temp;
}

string Fibonacci(int index){
	
	string res;
	
	temp[index%3]=temp[(index-1)%3];
	if(temp[index%3].size()==temp[(index-2)%3].size()){
		for(int i=0;i<temp[index%3].size();i++){
			temp[index%3][i]+=temp[(index-2)%3][i];
		}	
	}
	else{
		for(int i=1;i<temp[index%3].size();i++){
			temp[index%3][i]+=temp[(index-2)%3][i-1];
		}
	}
	
	for(int i=temp[index%3].size()-1;i>0;i--){
		temp[index%3][i-1]+=temp[index%3][i]/10;
		temp[index%3][i]=temp[index%3][i]%10;
	}
	
	while(temp[index%3][0]>9){
		temp[index%3].insert(temp[index%3].begin(),temp[index%3][0]/10);
		temp[index%3][1]=temp[index%3][1]%10;
	}
	
	
	for(int i=0;i<temp[index%3].size();i++){
		res+=temp[index%3][i]+'0';
	}
	
	
	while(temp[index%3].size()>maxn&&temp[(index-1)%3].size()>maxn){
		temp[index%3].erase(temp[index%3].end()-1);
		temp[(index-1)%3].erase(temp[(index-1)%3].end()-1);
	}
	return res;
}


void construct_tree(Node *r,string fibo,int index){
	int t;
	
	for(int i=0;i<fibo.length();i++){
		t=fibo[i]-'0';
		if(r->next[t]==NULL){
			r->next[t]=givenode();
		}
		
		if(!r->next[t]->has_value){
			r->next[t]->has_value=true;
			r->next[t]->index=index;
		}
		
		r=r->next[t];
	}
}

int search(string prefix,Node *r){
	int t;
	
	for(int i=0;i<prefix.length();i++){
		t=prefix[i]-'0';
		if(r->next[t]==NULL){
			return -1;
		}
		r=r->next[t];
	}
	
	if(!r->has_value){
		return -1;
	} 
	
	return r->index;
}


int main(void){
	//compute the Fibonacci number and construct the tree
	
	root=givenode();
	
	temp[0].push_back(1);
	temp[1].push_back(1);
	
	root->next[1]=givenode();
	root->next[1]->has_value=true;
	
	for(int i=2;i<maxm;i++){
		construct_tree(root,Fibonacci(i),i);
	}
	
	//receive the prefix and search the prefix in the tree
	int T;
	cin>>T;
	string buffer;
	while(T--){
		cin>>buffer;
		printf("Case #%d: %d\n",++kcase,search(buffer,root));
	}
} 
