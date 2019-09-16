#include<iostream>
#include<cstring>
#include<cstdio>
#include<set>
#include<map>
#include<vector>
using namespace std;

set<string> addr;
 
void helper(const string s,string &user,string &mta){
	int index=s.find('@');
	user=s.substr(0,index);
	mta=s.substr(index+1);
}
int main(void){
	string s,t,user1,mta1,user2,mta2;
	int k;
    while(cin>>s&&s!="*"){
    	cin>>s>>k;
    	while(k--){
    		cin>>t;
    		addr.insert(t+"@"+s);
		}
	}
	while(cin>>s&&s!="*"){
		helper(s,user1,mta1);
		
		vector<string> mtas;
		set<string> vis;
		map<string,vector<string> > dest;
		
		while(cin>>t&&t!="*"){
			helper(t,user2,mta2);
			if(vis.count(t)) continue; //去重 
			vis.insert(t);
			if(!dest.count(mta2)){
				mtas.push_back(mta2);
				dest[mta2]=vector<string>();
			}
			dest[mta2].push_back(t);
		}
		getchar();// 将单独的'*'去掉 
		
		string content;
		while(getline(cin,t)&&t!="*"){
			content+="     "+t+"\n";
		}
		
		for(int i=0;i<mtas.size();i++){
			string mta=mtas[i];
			vector<string> users=dest[mta];
			cout<<"Connection between "<<mta1<<" and "<<mta<<endl;
			cout<<"     HELO "<<mta1<<endl;cout<<"     250"<<endl;
			cout<<"     MAIL FROM:<"<<s<<">"<<endl;cout<<"     250"<<endl;
			bool flag=false;
			for(int j=0;j<users.size();j++){
				cout<<"     RCPT TO:<"<<users[j]<<">"<<endl;
				if(addr.count(users[j])){
					flag=true;
					cout<<"     250"<<endl;
				}
				else{
					cout<<"     550"<<endl;
				}
			}
			if(flag){
				cout<<"     DATA"<<endl;cout<<"     354"<<endl;
				cout<<content;
				cout<<"     .\n";cout<<"     250"<<endl;
			}
			cout<<"     QUIT\n";cout<<"     221\n";
		}
	}    	
} 
