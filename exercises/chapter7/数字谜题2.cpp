#include<iostream>
#include<string>
#include<cstdio>
#include<cstring> 
using namespace std;

const char dict[]="*0123456789";
const int size_dict=11;

string eqt,ans;
int lena,lenb,lenc;
int vis[8];
int cnt;

inline string inttostr(int n){
	string s="";
	while(n){
		s=(char)(n%10+'0')+s;
		n/=10;
	}
	return s;
}
inline int strtoint(string s){
	int sum=0;
	for(int i=0;i<s.length();i++){
		sum=sum*10+s[i]-'0';
	}
	return sum;
}
void check(int next){
	if(cnt>1) return;
	if(next==lena+lenb){
		int a=strtoint(eqt.substr(0,lena));
		int b=strtoint(eqt.substr(lena,lenb));
		string c=inttostr(a*b);
		string str=eqt.substr(lena+lenb,lenc);
		if(c.length()!=str.length()) return;
		for(int i=0;i<c.length();i++){
			if(c[i]!=str[i]&&str[i]!='*') return;
		}
		cnt++;
		return;
	}
	char temp=eqt[next];
	if(eqt[next]=='*'){
		for(int i=1;i<size_dict;i++){
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
bool dfs(int cur,int maxd){
	if(cur==maxd){
		if(judge()){
			ans=eqt;
			return true;
		}
		return false;
	}
	
	char temp;
	for(int i=0;i<lena+lenb+lenc;i++){
		if(vis[i]) continue;
		temp=eqt[i];
		for(int j=0;j<size_dict;j++){
			if((i==0||i==lena||i==lena+lenb)&&j==1) continue;
			if(temp==dict[j]){
				vis[i]=1;
				if(dfs(cur,maxd)) return true;
				eqt[i]=temp;
				vis[i]=0;
			}
			else{
				eqt[i]=dict[j];
				vis[i]=1;
				if(dfs(cur+1,maxd)) return true;
				eqt[i]=temp;
				vis[i]=0;
			}
		}
		vis[i]=0;
	}
	return false;
}
void solve(){
	int maxd;
	for(maxd=0;maxd<8;maxd++){
		memset(vis,0,sizeof(vis));
		if(dfs(0,maxd)) break;
	}
}
int main(void){
	string a,b,c;
	int kcase=0;
	while(cin>>a&&a!="0"){
		cin>>b>>c;
		lena=a.length();lenb=b.length();lenc=c.length();
		eqt=a+b+c;
		solve();
		printf("Case %d: ",++kcase);
		cout<<ans.substr(0,lena)<<" "
		<<ans.substr(lena,lenb)<<" "
		<<ans.substr(lena+lenb,lenc)<<endl;
	}
}
