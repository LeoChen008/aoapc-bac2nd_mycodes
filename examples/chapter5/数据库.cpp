#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

const int max_r=1000+10;
const int max_c=10+5;

vector<string> str;
vector<int> data[max_r];
map<string,int> IDcache;

struct Node{
	int c1,c2;
	Node(int a=0,int b=0){
		c1=a;
		c2=b;
	}
	bool operator < (const Node &n) const {
	    return c1<n.c1||c1==n.c1&&c2<n.c2;	
	}
};

map<Node,int> res;


void split(vector<string> &v,const string s,const char delim){
	v.clear();
	int begin=0;
	for(int i=0;i<s.length();i++){
		if(s[i]==delim){
			v.push_back(s.substr(begin,i-begin));
			begin=i+1;
		}
		if(i==s.length()-1){
			v.push_back(s.substr(begin,s.length()-begin));
		} 
	}
}
int id_alloced(const string s){
	if(IDcache.count(s)) return IDcache[s];
	str.push_back(s);
	return IDcache[s]=str.size()-1;
}
int main(){
	int n,m;
	while(cin>>n>>m){
		string s;
		vector<string> v;
		for(int i=0;i<n;i++){
			cin>>s;
			split(v,s,',');
			for(int j=0;j<m;j++){
				data[i].push_back(id_alloced(v[j]));
			}
		}
		bool flag=false;
		for(int c1=0;c1<m;c1++){
			for(int c2=c1+1;c2<m;c2++){
				res.clear();
				for(int r=0;r<n;r++){
					Node node(data[r][c1],data[r][c2]);
					if(!res.count(node)) res[node]=r;
					else{
					    cout<<"NO"<<endl;
						cout<<res[node]+1<<" "<<r+1<<endl;
						cout<<c1+1<<" "<<c2+1<<endl;
						flag=true;
						break;
					}
				}
				if(!flag)break;
			}
			if(!flag)break;
		}
		if(!flag)cout<<"YES"<<endl;
		for(int i=0;i<n;i++) data[i].clear();
		str.clear();
		IDcache.clear();
		res.clear();
	}
}
