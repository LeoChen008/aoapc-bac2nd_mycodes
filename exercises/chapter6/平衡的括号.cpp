#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<string>
using namespace std;

string str;

int main(void){
	int n;
	cin>>n;
	getchar();
	while(n--){
		getline(cin,str);
		
		int len=str.length();
		
		if(len%2){
			printf("No\n");
			continue;
		}
		stack<char> s;

		for(int i=0;i<len;i++){
			if(str[i]=='('||str[i]=='['){
				s.push(str[i]);
			}
			else if(!s.empty()&&s.top()=='('&&str[i]==')'){
				s.pop();
			}
			else if(!s.empty()&&s.top()=='['&&str[i]==']'){
				s.pop();
			}
		}
		if(s.empty()) printf("Yes\n");
		else printf("No\n");
	}
} 
