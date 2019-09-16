#include<iostream>
#include<cstdio>
#include<stringstream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

const int maxn=10000;

map<string,int> m;
vector<int> depend1[maxn],depend2[maxn];
string names[maxn];
int status[maxn];
int id;
string s;
stringstream ss;



int getid(const string item){
	if(!m.count(item)){
		names[++id]=item;
		m[item]=id;
	}
	return m[item];
} 
void setdepend(){
	string item;
	ss>>item;
	int id1=getid(item);
	int id2;
	while(ss>>item){
		id2=getid(item);
		depend1[id1].push_back(id2);
		depend2[id2].push_back(id1);
	}
}
void setinstall(){
	string item;
	ss>>item;
	int id1=getid(item);
	
	
}
void setremove(){
	
}
void showlist(){
	int i;
	for(i=0;i<maxn;i++){
		if(status[i]){
			cout<<"   "<<names[i]<<endl;
		} 
	}
}
void init(){
	memset(status,0,sizeof(status));
	id=0;
} 

int main(void){
	while(getline(cin,s)){
		init();
		string item;
		ss<<s;
		ss>>item;
		
		if(item=="END") return 0;
		else if(item=="DEPEND"){
			setdepend();
		}
		else if(item=="INSTALL"){
			setinstall();
		}
		else if(item=="REMOVE"){
			setremove();
		}
		else if(item=="LIST"){
			showlist();
		}
	}
} 

