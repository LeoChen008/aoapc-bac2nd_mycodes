#include<iostream>
#include<queue>
#include<set>
#include<vector>
using namespace std;

typedef long long LL;
const int factor[3]={2,3,5};

int main(void){
	priority_queue<LL,vector<LL>,greater<LL> >pq;
	set<LL> s;
	s.insert(1);
	pq.push(1);
	for(int i=1;;i++){
		LL x=pq.top();pq.pop();
		if(i==1500){
			cout<<"The 1500'th ugly number is "<<x<<".\n";
			break;
		}
		for(int j=0;j<3;j++){
			LL y=x*factor[j];
			if(!s.count(y)){
				s.insert(y);
				pq.push(y);
			}
		}
	}
}
