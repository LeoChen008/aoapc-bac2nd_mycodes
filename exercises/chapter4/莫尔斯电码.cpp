#include<iostream>
#include<string>
#include<map> 
#include<cstdio>

using namespace std;
 
typedef map<string,string> Map;

inline
int find_prefix(const string& ms,const string& ss){
	if(ms==ss) return true;
	if(ss.length()>ms.length()) return false;
	
	int start=ss.length();
	for(int i=start;i>=0;i--){
		if(ms.substr(0,i)==ss) return ms.length()-i;
	}
	
	return -1;
}

void encode_word(const Map& dic,Map& context,const string& word){
	if(dic.empty()) return;
	
	string val="";
	string key=word;
	
	string s;
	for(int i=0;i<word.length();i++){
	     s.push_back(word[i]);	
		 val+=dic.at(s);
		 s.clear();
	}
	
	context.insert(make_pair(key,val));	
}

string decode_word(const Map& context,const string& code){
	string res="";
	
	int cnt=0;
	//Exact Match 
	for(auto& iter:context){
		if(iter.second==code){
			if(!cnt)res=iter.first;
			cnt++;
		}
		
		if(cnt>1) return res+"!"; 
	}
	
	if(cnt==1) return res;
	
	//Fuzzy Match
	int min=0x3f3f3f3f;
	int res1=0,res2=0;
	res=context.begin()->first;
	for(auto& iter:context){
		res1=find_prefix(iter.second,code);
		res2=find_prefix(code,iter.second);
		if(res1>0&&min>res1){
			min=res1;
			res=iter.first;
		}
		else if(res2>0&&min>res2){
			min=res2;
			res=iter.first;
		}
	}
	
	return res+"?";
}

int main(void){
	Map dic,context;
	ios::sync_with_stdio(false);
	string k,v;
	dic.clear();
	//get dictionary's key and value. 
	while(cin>>k&&k!="*"){
		cin>>v;
		dic.insert(make_pair(k,v));
	}
	
	string word;
	context.clear();
	//get word and construct the map.
	while(cin>>word&&word!="*"){
		encode_word(dic,context,word);
	}
	
	string code;
	string res;
	//decode the morse code and print result;
	while(cin>>code&&code!="*"){
		res=decode_word(context,code);
		cout<<res<<endl;
	}
} 
