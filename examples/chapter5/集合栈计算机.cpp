#include<iostream>
#include<stack>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
#include<cctype>
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
using namespace std;

typedef set<int> Set;
stack<int> s;
vector<Set> setcache;
map<Set,int> idcache;

int ID(Set x){
	if(idcache.count(x)) return idcache[x];
	else{
		setcache.push_back(x);
	}
	return idcache[x]=setcache.size()-1;
}

int main(void){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			string op;
			cin>>op;
			if(op[0]=='P'){
				s.push(ID(Set()));
			}
			else if(op[0]=='D'){
				s.push(s.top());
			}
			else{
				Set x1=setcache[s.top()];s.pop();
				Set x2=setcache[s.top()];s.pop();
				Set x;
				if(op[0]=='U'){
					set_union(ALL(x1),ALL(x2),INS(x));
				}
				if(op[0]=='I'){
					set_intersection(ALL(x1),ALL(x2),INS(x));
				}
				if(op[0]=='A'){
					x=x2;
					x.insert(ID(x1));
				}
				s.push(ID(x));
			}
			cout<<setcache[s.top()].size()<<endl;
		}
		cout<<"***"<<endl;
	}
}
