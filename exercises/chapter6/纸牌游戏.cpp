#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>

using namespace std;


const int maxn=52;

struct Card{
	char suit;
	char rank;
	
	Card(char rank='0',char suit='0'):rank(rank),suit(suit){}
	
	bool operator==(const Card& card){
		return this->rank==card.rank||this->suit==card.suit;
	}
};

vector< stack<Card> > piles;

int main(void){
	string buffer;
	while(cin>>buffer&&buffer[0]!='#'){
		piles.clear();
		
		stack<Card> s;
		s.push(Card(buffer[0],buffer[1]));
		
		piles.push_back(s);
		
		for(int i=1;i<=maxn-1;i++){
			cin>>buffer;
			stack<Card> s;
			s.push(Card(buffer[0],buffer[1]));
		
			piles.push_back(s);
		}
		
		vector< stack<Card> >::iterator it;
		
		stack<Card> tem,tem3,tem1;
		while(1){
			for(it=piles.begin();it!=piles.end();it++){
			
				tem=*it;
				
				if(it>piles.begin()+2) tem3=*(it-3);
				if(it>piles.begin())   tem1=*(it-1);
			
		    	if(it> piles.begin()+2 && tem.top()== tem3.top()){
					tem3.push(tem.top());
					tem.pop();
					*(it-3)=tem3;
					break;
				}
				if(it> piles.begin() && tem.top()== tem1.top()){
					tem1.push(tem.top());
					tem.pop();
					*(it-1)=tem1;
					break;
				}
			}
			
			if(it==piles.end()){
				break;
			}
			if(tem.empty()){
				piles.erase(it);
			}
			else{
				*it=tem;
			}
			
		}
		if(piles.size()>1) printf("%d piles remaining:",piles.size());
		else{
			printf("1 pile remaining:");
		}
		for(int i=0;i<piles.size();i++){
			printf(" %d",piles[i].size());
		}
		printf("\n");
	}
}
