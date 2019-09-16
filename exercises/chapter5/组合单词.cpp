#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<vector>
#include<string> 
#include<algorithm>
using namespace std;

set<string> s;
vector<string> ans;

int main(void){
	
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	string buffer;
	while(cin>>buffer){

		s.insert(buffer);
	}
	
	set<string>::iterator iter;
	
	for(iter=s.begin();iter!=s.end();iter++){
		string temp=*iter;
		
		for(int len=1;len<temp.length();len++){
			string s1=temp.substr(0,len);
			string s2=temp.substr(0+len,temp.length()-len);
				
			if(s.count(s1)&&s.count(s2)){
				ans.push_back(temp);
				break;
			}
				
		}
			
	}
	
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++) cout<<ans[i]<<endl;
	
	fclose(stdin);
	fclose(stdout);
}
