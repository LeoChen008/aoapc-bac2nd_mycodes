#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<map>
#include<sstream>
#include<algorithm>
using namespace std;

const int maxn=10000;

map<string,int> m;
string items[maxn];
vector<int> depend1[maxn],depend2[maxn];
int status[maxn];    //0表示没安装,1表示显示安装,2表示隐式安装 
int id;
vector<int> installed; //表示所有已安装的组件 
stringstream ss;
string s;

int getId(const string s){
	if(!m.count(s)){
		items[++id]=s;
		m[s]=id;
	}
	return m[s];
}


void setDepend(){
	ss.clear();
	ss<<s;
	
	string item;
	int id1,id2;
	ss>>item;
	
	id1=getId(item);
	
	while(ss>>item){
		id2=getId(item);
		depend1[id1].push_back(id2);
		depend2[id2].push_back(id1);		
	}
}
void install(int id,bool toplevel){
	if(!status[id]){
		int i;
		for(i=0;i<depend1[id].size();i++){
			install(depend1[id][i],false);
		}
		
		cout<<"   Installing "<<items[id]<<endl;
		status[id]=toplevel?1:2;
		installed.push_back(id);
	}
}

void getInstall(){
	ss.clear();
	ss<<s;
	
	string item;
	ss>>item;
	
	int id1=getId(item);
	int i;
	
	if(status[id1]){
		cout<<"   "<<item<<" is already installed."<<endl;
		return;
	}
	
	install(id1,true);
}
bool needed(int id){
	int i;
	for(i=0;i<depend2[id].size();i++){
		if(status[depend2[id][i]]) return true;
	}
	return false;
}

void remove(int id,int toplevel){
	if((toplevel||status[id]==2)&&!needed(id)){
		status[id]=0;
		installed.erase(remove(installed.begin(),installed.end(),id),installed.end());
		cout<<"   Removing "<<items[id]<<endl;
		for(int i=0;i<depend1[id].size();i++){
			remove(depend1[id][i],false);
		}
	}
}


void getRemove(){
	ss.clear();
	ss<<s;
	
	string item;
	ss>>item;
	
	int id1=getId(item);
	int i;
	
	if(!status[id1]){
		cout<<"   "<<item<<" is not installed."<<endl;
	}
	else if(needed(id1)){
		cout<<"   "<<item<<" is still needed."<<endl;
	}
	else{
		remove(id1,true);
	}
}

void showList(){
	int i;
	for(i=0;i<installed.size();i++){
		cout<<"   "<<items[installed[i]]<<endl;
	}
}


int main(void){
	while(getline(cin,s)){
		id=0;
		memset(status,0,sizeof(status));
		installed.clear();
		do{
			cout<<s<<endl;
			if(s[0]=='E') break;
			else if(s[0]=='D'){
				s.erase(0,6);
				setDepend();
			}
			else if(s[0]=='I'){
				s.erase(0,7);
				getInstall();
			}
			else if(s[0]=='R'){
				s.erase(0,6);
				getRemove();
			}
			else if(s[0]=='L'){
				showList();
			}
		}while(getline(cin,s));
	}
} 
