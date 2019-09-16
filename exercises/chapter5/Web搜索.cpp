#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctype.h>
#include<sstream>
#include<map>
#include<vector>
#include<set>
 
using namespace std;

vector< vector<string> > docs;
map<string,set< pair<int,int> > > inverttable;


int n,m;


vector<string> getwords(const string query,int *mode){
	
	vector<string> words;
	stringstream ss;
	string s;
	
	ss<<query;
	
	while(!ss.fail()){
		ss>>s;
		if(s=="NOT"){
			*mode=3;
		}else if(s=="AND"){
			*mode=1;
		}else if(s=="OR"){
			*mode=2;
		}else{
			words.push_back(s);
		}
	}
	return words;
}


void construct_inverttable(vector<string> doc,int id){
	int len=doc.size();
	int i;
	stringstream ss;
	
	for(i=0;i<len;i++){
		string s=doc[i];
		ss.clear();
		ss<<s;
		while(!ss.fail()){
			ss>>s;
			string::iterator iter;
			for(iter=s.begin();iter<s.end();iter++){
				if(isalpha(*iter)){
					*iter=tolower(*iter);
				}else{
					iter=s.erase(iter);
				}
			}
			pair<int,int> p(id,i);
			if(inverttable.count(s)){
				inverttable[s].insert(p);
				
			}else{
				set< pair<int,int> > sset;
				sset.insert(p);
				inverttable[s]=sset;
			}
		}
	}
}

void search_and_print(const vector<string> words,int mode){
	
	set< pair<int,int> >::iterator iter,iter2;
	set< pair<int,int> > s,s2;
	pair<int,int> p,p2;
	string str,str2;
	int doc,line,doc2,line2;
	bool flag=false;
	
	switch(mode){
		case 0:
			str=words[0];
			if(inverttable.count(str)){
				s=inverttable[str];
				
				iter=s.begin();
				for(;iter!=s.end();){
					p=*iter;
					doc=p.first;
					line=p.second;
					
					cout<<docs[doc][line]<<endl;
					iter++;
					if(iter!=s.end()) cout<<"---------"<<endl;
				}
			}
			else{
				cout<<"Sorry, I found nothing."<<endl;
			}
			cout<<"=========="<<endl;
			break;
		case 1:
			str=words[0];
			str2=words[1];
			
			if(inverttable.count(str)&&inverttable.count(str2)){
				s=inverttable[str];
				s2=inverttable[str2];
			
				iter=s.begin();
				iter2=s2.begin();
			
				for(;iter!=s.end();iter++){
					p=*iter;
					doc=p.first;
					for(;iter2!=s2.end();iter2++){
						p2=*iter2;
						doc2=p2.first;
						
						if(doc==doc2){
							flag=true;
							line=p.second;
							line2=p2.second;
							
							cout<<docs[doc][line]<<endl;
							cout<<docs[doc2][line2]<<endl;
						}
					}
				}
				
				if(!flag){
					cout<<"Sorry, I found nothing."<<endl;
				}
			}
			else{
				cout<<"Sorry, I found nothing."<<endl;
			}
			cout<<"=========="<<endl;
			break;
			
		case 2:break;
		case 3:break;	
	}
}
int main(void){
	
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	cin>>n;
	
	getchar();
	for(int i=0;i<n;i++){ 
		string buffer;
		vector<string> lines;
		
		while(getline(cin,buffer)){
			if(buffer=="**********") break;
			lines.push_back(buffer);			
		}
		
		docs.push_back(lines);
		construct_inverttable(lines,i);
	}
	
	cin>>m;
	vector<string> words;
	string query;
	int mode=0;
	getchar();
	while(m--){
		getline(cin,query);
		mode=0;
		words=getwords(query,&mode);
		search_and_print(words,mode);
	}
	
	//fclose(stdin);
	//fclose(stdout);
} 
