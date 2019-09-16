#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

const char dict[]={'*','0','1','2','3','4','5','6','7','8','9'};
const int size_dict=11;
#define _DEBUG
string eqt;
string ans;
int lena,lenb,lenc;
int cnt;

inline string inttostr(int n){
	string s="";
	while(n){
		s=(char)(n%10+'0')+s;
		n/=10;
	}
	return s;
}
inline int strtoint(string str){
	int len=str.length();
	int sum=0;
	for(int i=0;i<len;i++){
		sum=sum*10+str[i]-'0';
	}
	return sum;
}
void check(int next){
	if(cnt>1) return;
	if(next==lena+lenb){
		string str;
		str=eqt.substr(lena+lenb,lenc);
		int a=strtoint(eqt.substr(0,lena));
		int b=strtoint(eqt.substr(lena,lenb));
		string c=inttostr(a*b);
		if(c.length()!=str.length()) return;
		for(int i=0;i<c.length();i++){
			if(c[i]!=str[i]&&str[i]!='*') return;
		}
		cnt++;
		return;
	}
	if(eqt[next]=='*'){
		char temp=eqt[next];
		for(int i=1;i<size_dict;i++){
			if(cnt>1) return;
			if((next==0||next==lena||next==lena+lenb)&&i==1) continue;
			eqt[next]=dict[i];
			check(next+1);
			eqt[next]=temp;
		}
	}else{
		check(next+1);
	}
}
bool judge(){
	cnt=0;
	check(0);
	if(cnt==1) return true;
	return false;
}
bool dfs(int cur,int next,int maxd){
	if(cur==maxd){
		if(judge()){
			ans=eqt;
			return true;
		}
		return false;
	}
	if(next>=lena+lenb+lenc) return false;
	char temp=eqt[next];
	
	for(int i=0;i<size_dict;i++){
		if((next==0||next==lena||next==lena+lenb)&&i==1) continue;//ºöÂÔÇ°µ¼0
		if(temp==dict[i]){
			if(dfs(cur,next+1,maxd)) return true;
		}
		else{
			eqt[next]=dict[i];
			if(dfs(cur+1,next+1,maxd)) return true;
			eqt[next]=temp;
		} 
	}
	return false;	
} 
void solve(){
	int maxd;
	for(maxd=0;maxd<=8;maxd++){ 
		if(dfs(0,0,maxd)){
			return;
		}
	}
} 
int main(void){
	#ifdef DEBUG
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	string a,b,c;
	int kcase=0;
	while(cin>>a&&a!="0"){
		cin>>b>>c;
		lena=a.length();lenb=b.length();lenc=c.length();
		eqt=a+b+c;
		solve();
		printf("Case %d: ",++kcase);
		cout<<ans.substr(0,lena)<<" "<<
		ans.substr(lena,lenb)<<" "<<
		ans.substr(lenb+lena,lenc)<<endl; 
	}
	
	fclose(stdin);
	fclose(stdout);
}  
