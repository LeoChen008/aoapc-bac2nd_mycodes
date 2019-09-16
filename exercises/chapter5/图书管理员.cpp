#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

struct Book{
	string name;
	string author;
	
	Book(string name="",string author=""):name(name),author(author){}
	bool operator<(const Book &b)const {
		return (this->author.compare(b.author)<0)||
		(this->author.compare(b.author)==0&&this->name.compare(b.name)<0);
	}
};

vector<Book> shelves;
vector<int> ans;
map<string,int> getorder;
map<string,int> state;


string getname(const string buffer){
	int pos=buffer.find("\"",1);
	string name=buffer.substr(1,pos-1);
	
	return name;
}


string getauthor(const string buffer){
	int pos=buffer.find("by");
	pos+=3;
	
	int len=buffer.length();
	
	string author=buffer.substr(pos,len-pos);
	
	return author;
}



string getname2(const string buffer){
	int pos=buffer.find("\"");
	pos++;
	int len=buffer.length();
	string name=buffer.substr(pos,len-pos-1);
	
	return name;
}

bool nobefore(int index,int &before){
	if(index==0) return true;
	
	for(int i=index-1;i>=0;i--){
		if(state[shelves[i].name]==1){
			before=i;
			return false;
		}
	}
	
	return true;
}

int main(void){
	
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	string buffer;
	while(getline(cin,buffer)&&buffer!="END"){
		string name=getname(buffer);
		string author=getauthor(buffer);
		
		shelves.push_back(Book(name,author));
	}
	
	sort(shelves.begin(),shelves.end());
	
	for(int i=0;i<shelves.size();i++){
		Book temp=shelves[i];
		
		getorder[temp.name]=i;
		state[temp.name]=1;
	}
	
	while(getline(cin,buffer)&&buffer!="END"){
		char ins=buffer[0];
		
		if(ins=='B'){
			string name=getname2(buffer);
			
			state[name]=0;
		}
		else if(ins=='R'){
			string name=getname2(buffer);
			
			state[name]=-1;
		}
		else if(ins=='S'){
			map<string,int>::iterator iter;
			for(iter=state.begin();iter!=state.end();iter++){
				if(iter->second==-1){
					string s=iter->first;
					int order=getorder[s];
					
					ans.push_back(order);
				}
			}
			
			
			sort(ans.begin(),ans.end());
			
			for(int i=0;i<ans.size();i++){
				int index=ans[i];
				int before=0;
				
				if(nobefore(index,before)){
					cout<<"Put \""<<shelves[index].name<<"\" first"<<endl;
					state[shelves[index].name]=1;
				}
				else if(!nobefore(index,before)){
					cout<<"Put \""<<shelves[index].name<<"\" after \""<<shelves[before].name<<"\""<<endl;
					state[shelves[index].name]=1;
				}
			}
			
			
			printf("END\n");
			ans.clear();
		} 
	}
	
	//fclose(stdin);
	//fclose(stdout);
}
