#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<map>
#include<vector>
using namespace std;

string dealwords(string buffer){
	string str;
	str=buffer.substr(1,buffer.length()-2);
	
	int len=str.length();
	for(int i=0;i<len;i++){
		if(str[i]==',') str[i]=' ';
	}
	
	return str;
}
map<string,string> setdict(string dict,map<string,string> m){
	int p;
	string s;
	stringstream ss(dict);
	while(ss>>s){
		p=s.find(':');
		m[s.substr(0,p)]=s.substr(p+1);
	}
	
	return m;
}
int main(void){
	int T;
	cin>>T;
	
	map<string,string> m;
    map<string,string> m2;
    map<string,string>::iterator iter1,iter2;
    vector<string> res_plus;
    vector<string> res_minus;
    vector<string> res_change; 
    
    bool flag1,flag2,flag3;
    
    string olddict,newdict;
    
	while(T--){
		m.clear();
		m2.clear();
		
		res_plus.clear();
		res_minus.clear();
		res_change.clear();
		
		
		flag1=flag2=flag3=false;
		
		cin>>olddict;
		olddict=dealwords(olddict);
		
		m=setdict(olddict,m);
		
		cin>>newdict;
		newdict=dealwords(newdict);
		
		m2=setdict(newdict,m2);
		
		for(iter2=m2.begin();iter2!=m2.end();iter2++){
			
			pair<string,string> p=*iter2;
			string k=p.first;
			if(!m.count(k)){
				flag1=true;
				res_plus.push_back(k);
			}
		} 
		
		for(iter1=m.begin();iter1!=m.end();iter1++){
			pair<string,string> p=*iter1;
			string k=p.first; 
			
			if(!m2.count(k)){
				flag2=true;
				res_minus.push_back(k);
			}
			else{
				pair<string,string> p2=*iter1;
				string val=p2.second;
				string val2=m2[k];
				
				if(val!=val2){
					flag3=true;
					res_change.push_back(k);
				}
			}
		}
		
		
		if(!flag1&&!flag2&&!flag3){
			cout<<"No changes"<<endl<<endl;
		}
		else{
			
			if(flag1){
				printf("+");
				for(int i=0;i<res_plus.size()-1;i++){
					cout<<res_plus[i];
					printf(",");
				}
				cout<<res_plus[res_plus.size()-1]<<endl;
			}
			
			if(flag2){
				printf("-");
				for(int i=0;i<res_minus.size()-1;i++){
					cout<<res_minus[i];
					printf(",");
				}
				cout<<res_minus[res_minus.size()-1]<<endl;
			}
			
			if(flag3){
				printf("*");
				for(int i=0;i<res_change.size()-1;i++){
					cout<<res_change[i];
					printf(",");
				}
				
				cout<<res_change[res_change.size()-1]<<endl;
			}
			
			printf("\n");
	    }
		
	}	
}
