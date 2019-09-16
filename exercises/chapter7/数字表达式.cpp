#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;

const int maxn=9;
const char oper[]={'#','*','+','-'};
string equa;
char add[maxn];
set<string> ans;

string get_eqa(){
	string s="";
	for(int i=0;i<equa.length();i++){
		s+=equa[i];
		if(add[i]!='#'){
			s+=add[i];
		}
	}
	return s;
}

bool judge(string s){
	int sum=0;
	int num[maxn];
	char opr[maxn];
	int n1=0;
	int op1=0;
	bool flag=false;
	bool mul=false; 
	 
	for(int i=0;i<=s.length();i++){
		if(isdigit(s[i])){
			sum=sum*10+s[i]-'0';
			if(flag) return false;
			if(sum==0) flag=true;
		}
		else if(mul){
			int last=num[--n1];
			num[n1++]=last*sum;sum=0;
			flag=false;
			if(s[i]!='*'){
				opr[op1++]=s[i];
				mul=false;
			}
		}
		else if(s[i]=='*'){
			num[n1++]=sum;sum=0;
			mul=true;
			flag=false;
		}
		else{
			num[n1++]=sum;sum=0;
			opr[op1++]=s[i];
			flag=false;
		}
	}
	sum=num[0];
	for(int i=1;i<n1;i++){
		if(opr[i-1]=='-') sum-=num[i];
		else{
			sum+=num[i];
		}
	}
	
	if(sum==2000) return true;
	return false;
}

void dfs(int cur,int maxd){
	if(cur==maxd){
		string s=get_eqa();
		if(judge(s)){
			ans.insert(s);
		}
		
		return;
	}
	
	for(int i=0;i<4;i++){
		add[cur]=oper[i];
		dfs(cur+1,maxd);
	}
}
int main(void){
	string buffer;
	int kcase=0;
	while(cin>>buffer&&buffer!="="){		
		ans.clear();
		
		if(buffer=="2000=") goto PRINT_ANS;
		equa=buffer.substr(0,buffer.length()-1);
		for(int i=0;i<equa.length();i++){
			add[i]='#';
		}
		dfs(0,equa.length()-1);
		
		PRINT_ANS:
		printf("Problem %d\n",++kcase);
		if(!ans.empty()){
			for(set<string>::iterator iter=ans.begin();iter!=ans.end();iter++){
				cout<<"  "<<*iter<<"="<<endl;
			}
		}
		else printf("  IMPOSSIBLE\n");
	}
} 
