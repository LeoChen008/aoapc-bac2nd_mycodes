#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<cstdlib>
using namespace std;

const int maxn=1000+5;

int line;

struct Array{
	map<int,int> val;
	int len;
	Array(int len=0):len(len){}
}arrays[maxn];



void init(){
	for(int i='A';i<='z';i++) {
		arrays[i].val.clear();
		arrays[i].len=0;
	}
	line=0;
}

void divide(const string buffer,string &left,string &right){
	int equal=buffer.find('=');
	
	if(equal==-1){
		left=buffer;
		right="";
	} 
	else{
		left=buffer.substr(0,equal);
		right=buffer.substr(equal+1);
	}
}

void getvalue(const string s,string &value){
	int bracebg=s.find('[');
	int braceed=s.find_last_of(']');
	
	if(bracebg!=-1){
		value=s.substr(bracebg+1,braceed-bracebg-1);
	}
	else{
		value=s;
	}
}

int dfs(string s){
	if(s[0]>='0'&&s[0]<='9'){
		return atoi(s.c_str());
	}
	
	int arr=s[0];
	string value;
	getvalue(s,value);
	
	int index=dfs(value);
	
	if(index>=0&&index<arrays[arr].len&&arrays[arr].val.count(index)){
		return arrays[arr].val[index]; 
	}
	return -1;
}

int main(void){
	string buffer;
	bool iffirst=true;
	bool mark=false;
	line=0;
	
	while(cin>>buffer){
		if(buffer!="."){
			
			line++;
			mark=false;
			
			string left,right;
			divide(buffer,left,right);
			
			if(right==""){
				int arr=left[0];
				string value; 
				getvalue(left,value);
				arrays[arr].len=atoi(value.c_str());
			}
			else{
				int arr=left[0];
				string value;
				getvalue(left,value);
				int index=dfs(value);
				int valueright=dfs(right);
				
				if(index>=0&&index<arrays[arr].len&&valueright!=-1){
					arrays[arr].val[index]=valueright;
				}
				else{
					
					if(iffirst){
						cout<<line<<endl;
						iffirst=false;
					}
				}
			}
			
		}
		else{
			init();
			if(mark) break;
			else{
				if(iffirst){
					cout<<0<<endl;
				}
				iffirst=true;
				mark=true;	
			}
		}
	}
} 
