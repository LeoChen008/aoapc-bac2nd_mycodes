#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<cctype>
using namespace std;

map<string,int> dict;
vector<string> words;

string helper(const string &s){
	string a=s;
	for(int i=0;i<a.length();i++){
		a[i]=tolower(a[i]);
	}
	sort(a.begin(),a.end());
	return a;
}
int main(void){
	string s;
	while(cin>>s){
		if(s[0]=='#')break;
		words.push_back(s);
		string r=helper(s);
		if(!dict.count(r)) dict[r]=0;
		dict[r]++;
	}
	vector<string> ans;
	for(int i=0;i<words.size();i++){
		if(dict[helper(words[i])]==1){
			ans.push_back(words[i]);
		}
	}
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}
}
